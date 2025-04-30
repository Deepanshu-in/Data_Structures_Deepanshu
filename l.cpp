#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

/**
 * दिशा के लिए एनम
 * खिलाड़ी के आगे बढ़ने की दिशा को ट्रैक करने के लिए उपयोग किया जाता है
 */
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

/**
 * खाद्य प्रकार के लिए एनम
 * सामान्य खाद्य और विशेष खाद्य के बीच अंतर करने के लिए
 */
enum FoodType
{
    NORMAL,
    SPECIAL
};

/**
 * Point क्लास
 * 2D ग्रिड पर एक स्थान को प्रतिनिधित्व करता है
 */
class Point
{
public:
    int x, y;

    /**
     * कंस्ट्रक्टर
     * @param x X-निर्देशांक
     * @param y Y-निर्देशांक
     */
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    /**
     * समानता ऑपरेटर
     * दो बिंदुओं की तुलना करने के लिए
     * @param other तुलना के लिए अन्य बिंदु
     * @return यदि दोनों बिंदु एक ही स्थान पर हैं तो सही
     */
    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

/**
 * Food क्लास
 * गेम में खाद्य पदार्थों को प्रतिनिधित्व करता है
 */
class Food
{
private:
    Point position; // खाद्य की स्थिति
    char symbol;    // खाद्य का प्रतीक
    FoodType type;  // खाद्य प्रकार (सामान्य या विशेष)

public:
    /**
     * कंस्ट्रक्टर
     * @param maxX अधिकतम X-निर्देशांक
     * @param maxY अधिकतम Y-निर्देशांक
     */
    Food(int maxX, int maxY) : symbol('$'), type(NORMAL)
    {
        // खाद्य की स्थिति को रेंडम तरीके से निर्धारित करें
        position.x = rand() % (maxX - 2) + 1;
        position.y = rand() % (maxY - 2) + 1;

        // 20% संभावना है कि यह एक विशेष खाद्य होगा
        if (rand() % 5 == 0)
        {
            type = SPECIAL;
            symbol = '*';
        }
    }

    /**
     * खाद्य की स्थिति प्राप्त करें
     * @return खाद्य की स्थिति
     */
    Point getPosition() const { return position; }

    /**
     * खाद्य का प्रतीक प्राप्त करें
     * @return खाद्य प्रतीक ('$' या '*')
     */
    char getSymbol() const { return symbol; }

    /**
     * खाद्य प्रकार प्राप्त करें
     * @return खाद्य प्रकार (सामान्य या विशेष)
     */
    FoodType getType() const { return type; }

    /**
     * खाद्य पुनः उत्पन्न करें
     * @param maxX अधिकतम X-निर्देशांक
     * @param maxY अधिकतम Y-निर्देशांक
     * @param obstacles अवरोधों की सूची जिन्हें खाद्य पदार्थों को टकराने से बचाना चाहिए
     */
    void respawn(int maxX, int maxY, const std::vector<Point> &obstacles)
    {
        bool validPosition = false;

        // एक वैध स्थिति खोजें जो किसी भी अवरोध के साथ ओवरलैप न करे
        while (!validPosition)
        {
            position.x = rand() % (maxX - 2) + 1;
            position.y = rand() % (maxY - 2) + 1;

            validPosition = true;
            for (const auto &obstacle : obstacles)
            {
                if (position == obstacle)
                {
                    validPosition = false;
                    break;
                }
            }
        }

        // 20% संभावना है कि यह एक विशेष खाद्य होगा
        if (rand() % 5 == 0)
        {
            type = SPECIAL;
            symbol = '*';
        }
        else
        {
            type = NORMAL;
            symbol = '$';
        }
    }
};

/**
 * Snake क्लास
 * प्रत्येक प्लेयर के सांप को प्रतिनिधित्व करता है
 */
class Snake
{
private:
    std::deque<Point> body; // सांप के शरीर के सभी खंडों की सूची
    Direction direction;    // सांप की वर्तमान दिशा
    char symbol;            // सांप का प्रतीक
    int score;              // सांप का स्कोर
    bool alive;             // क्या सांप जीवित है

public:
    /**
     * कंस्ट्रक्टर
     * @param x सिर की प्रारंभिक X स्थिति
     * @param y सिर की प्रारंभिक Y स्थिति
     * @param symbol सांप का प्रतीक
     */
    Snake(int x, int y, char symbol) : direction(RIGHT), symbol(symbol), score(0), alive(true)
    {
        body.push_front(Point(x, y));
    }

    /**
     * सांप की दिशा बदलें
     * @param newDir नई दिशा
     */
    void changeDirection(Direction newDir)
    {
        // सुनिश्चित करें कि सांप विपरीत दिशा में नहीं जा सकता
        if ((direction == UP && newDir != DOWN) ||
            (direction == DOWN && newDir != UP) ||
            (direction == LEFT && newDir != RIGHT) ||
            (direction == RIGHT && newDir != LEFT))
        {
            direction = newDir;
        }
    }

    /**
     * सांप को एक कदम आगे बढ़ाएं
     */
    void move()
    {
        if (!alive)
            return;

        Point head = body.front();
        Point newHead = head;

        // वर्तमान दिशा के आधार पर नया सिर स्थान निर्धारित करें
        switch (direction)
        {
        case UP:
            newHead.y--;
            break;
        case DOWN:
            newHead.y++;
            break;
        case LEFT:
            newHead.x--;
            break;
        case RIGHT:
            newHead.x++;
            break;
        }

        // नया सिर जोड़ें और पिछला खंड हटाएं
        body.push_front(newHead);
        body.pop_back();
    }

    /**
     * जांचें कि क्या सांप खाद्य पदार्थ खा सकता है
     * @param food खाद्य वस्तु
     * @return यदि खाद्य खाया गया तो सही
     */
    bool eat(const Food &food)
    {
        if (!alive)
            return false;

        Point head = body.front();
        if (head == food.getPosition())
        {
            // विशेष खाद्य दोगुने अंक देता है
            if (food.getType() == SPECIAL)
            {
                score += 20;
            }
            else
            {
                score += 10;
            }
            grow();
            return true;
        }
        return false;
    }

    /**
     * सांप को एक खंड तक बढ़ाएं
     */
    void grow()
    {
        Point tail = body.back();
        body.push_back(tail);
    }

    /**
     * टकराव के लिए जांचें
     * @param maxX अधिकतम X-निर्देशांक
     * @param maxY अधिकतम Y-निर्देशांक
     * @param other दूसरा सांप
     * @return यदि टकराव हुआ है तो सही
     */
    bool checkCollision(int maxX, int maxY, const Snake &other)
    {
        if (!alive)
            return false;

        Point head = body.front();

        // दीवारों के साथ टकराव
        if (head.x <= 0 || head.x >= maxX - 1 || head.y <= 0 || head.y >= maxY - 1)
        {
            alive = false;
            return true;
        }

        // स्वयं के शरीर के साथ टकराव
        for (size_t i = 1; i < body.size(); ++i)
        {
            if (head == body[i])
            {
                alive = false;
                return true;
            }
        }

        // अन्य सांप के शरीर के साथ टकराव
        for (const auto &segment : other.getBody())
        {
            if (head == segment)
            {
                alive = false;
                return true;
            }
        }

        return false;
    }

    /**
     * सांप के शरीर प्राप्त करें
     * @return सांप के शरीर के सभी खंडों की सूची
     */
    const std::deque<Point> &getBody() const { return body; }

    /**
     * सांप का प्रतीक प्राप्त करें
     * @return सांप का प्रतीक
     */
    char getSymbol() const { return symbol; }

    /**
     * सांप का स्कोर प्राप्त करें
     * @return वर्तमान स्कोर
     */
    int getScore() const { return score; }

    /**
     * जांचें कि क्या सांप जीवित है
     * @return यदि सांप जीवित है तो सही
     */
    bool isAlive() const { return alive; }

    /**
     * सांप के सभी बिंदुओं की एक सूची प्राप्त करें
     * @return सांप के शरीर के सभी बिंदुओं की सूची
     */
    std::vector<Point> getAllPoints() const
    {
        std::vector<Point> points;
        for (const auto &p : body)
        {
            points.push_back(p);
        }
        return points;
    }
};

/**
 * Game क्लास
 * गेम लॉजिक और रेंडरिंग प्रबंधित करता है
 */
class Game
{
private:
    int maxX, maxY;             // स्क्रीन का आकार
    Snake player1;              // प्लेयर 1 का सांप
    Snake player2;              // प्लेयर 2 का सांप
    Food food;                  // खाद्य वस्तु
    std::atomic<bool> gameOver; // गेम समाप्त फ्लैग
    std::mutex mtx;             // थ्रेड सिंक्रोनाइज़ेशन के लिए म्यूटेक्स

public:
    /**
     * कंस्ट्रक्टर
     * ncurses इनिशियलाइज़ करता है और गेम सेटअप करता है
     */
    Game() : maxX(0),
             maxY(0),
             player1(10, 10, '@'),
             player2(40, 10, '#'),
             food(0, 0),
             gameOver(false)
    {

        // ncurses इनिशियलाइज़ करें
        initscr();
        start_color();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0); // कर्सर छिपाएं
        timeout(0);  // गैर-ब्लॉकिंग getch() के लिए

        // कलर पेयर्स इनिशियलाइज़ करें
        init_pair(1, COLOR_RED, COLOR_BLACK);    // प्लेयर 1 के लिए लाल
        init_pair(2, COLOR_GREEN, COLOR_BLACK);  // प्लेयर 2 के लिए हरा
        init_pair(3, COLOR_YELLOW, COLOR_BLACK); // विशेष खाद्य के लिए पीला

        // स्क्रीन का आकार प्राप्त करें
        getmaxyx(stdscr, maxY, maxX);
        food = Food(maxX, maxY);
    }

    /**
     * डिस्ट्रक्टर
     * ncurses क्लीनअप करता है
     */
    ~Game()
    {
        endwin();
    }

    /**
     * कीबोर्ड इनपुट प्रोसेस करें
     * अलग थ्रेड में चलता है
     */
    void processInput()
    {
        while (!gameOver)
        {
            int ch = getch();
            if (ch != ERR)
            {
                std::lock_guard<std::mutex> lock(mtx);

                switch (ch)
                {
                // प्लेयर 1 के नियंत्रण (WASD)
                case 'w':
                    player1.changeDirection(UP);
                    break;
                case 's':
                    player1.changeDirection(DOWN);
                    break;
                case 'a':
                    player1.changeDirection(LEFT);
                    break;
                case 'd':
                    player1.changeDirection(RIGHT);
                    break;

                // प्लेयर 2 के नियंत्रण (IJKL)
                case 'i':
                    player2.changeDirection(UP);
                    break;
                case 'k':
                    player2.changeDirection(DOWN);
                    break;
                case 'j':
                    player2.changeDirection(LEFT);
                    break;
                case 'l':
                    player2.changeDirection(RIGHT);
                    break;

                // गेम से बाहर निकलने के लिए
                case 'q':
                    gameOver = true;
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

    /**
     * गेम स्टेट अपडेट करें
     */
    void update()
    {
        std::lock_guard<std::mutex> lock(mtx);

        // दोनों सांपों को मूव करें
        player1.move();
        player2.move();

        // अवरोधों की सूची बनाएं (दोनों सांपों के सभी खंड)
        std::vector<Point> obstacles;
        for (const auto &p : player1.getAllPoints())
            obstacles.push_back(p);
        for (const auto &p : player2.getAllPoints())
            obstacles.push_back(p);

        bool foodEaten = false;

        // जांचें कि क्या किसी भी खिलाड़ी ने खाद्य खाया है
        if (player1.eat(food))
        {
            foodEaten = true;
        }

        if (player2.eat(food))
        {
            foodEaten = true;
        }

        // यदि खाद्य खाया गया है, तो एक नया खाद्य पुनः उत्पन्न करें
        if (foodEaten)
        {
            food.respawn(maxX, maxY, obstacles);
        }

        // टकराव जांचें
        player1.checkCollision(maxX, maxY, player2);
        player2.checkCollision(maxX, maxY, player1);

        // जांचें कि क्या दोनों खिलाड़ी मर गए हैं
        if (!player1.isAlive() && !player2.isAlive())
        {
            gameOver = true;
        }
    }

    /**
     * गेम रेंडर करें
     */
    void render()
    {
        clear();

        // गेम की सीमाओं को ड्रा करें
        for (int i = 0; i < maxX; ++i)
        {
            mvaddch(0, i, '#');
            mvaddch(maxY - 1, i, '#');
        }

        for (int i = 0; i < maxY; ++i)
        {
            mvaddch(i, 0, '#');
            mvaddch(i, maxX - 1, '#');
        }

        // खाद्य पदार्थ ड्रा करें (विशेष खाद्य के लिए पीला रंग का उपयोग करें)
        if (food.getType() == SPECIAL)
        {
            attron(COLOR_PAIR(3));
            mvaddch(food.getPosition().y, food.getPosition().x, food.getSymbol());
            attroff(COLOR_PAIR(3));
        }
        else
        {
            mvaddch(food.getPosition().y, food.getPosition().x, food.getSymbol());
        }

        // प्लेयर 1 का सांप ड्रा करें (लाल रंग में)
        attron(COLOR_PAIR(1));
        for (const auto &p : player1.getBody())
        {
            mvaddch(p.y, p.x, player1.getSymbol());
        }
        attroff(COLOR_PAIR(1));

        // प्लेयर 2 का सांप ड्रा करें (हरे रंग में)
        attron(COLOR_PAIR(2));
        for (const auto &p : player2.getBody())
        {
            mvaddch(p.y, p.x, player2.getSymbol());
        }
        attroff(COLOR_PAIR(2));

        // स्कोर ड्रा करें
        mvprintw(0, maxX / 2 - 15, "Player 1: %d | Player 2: %d", player1.getScore(), player2.getScore());

        // यदि गेम ओवर है, तो परिणाम दिखाएं
        if (gameOver)
        {
            mvprintw(maxY / 2, maxX / 2 - 5, "GAME OVER");

            if (player1.getScore() > player2.getScore())
            {
                mvprintw(maxY / 2 + 1, maxX / 2 - 11, "Player 1 wins with %d points!", player1.getScore());
            }
            else if (player2.getScore() > player1.getScore())
            {
                mvprintw(maxY / 2 + 1, maxX / 2 - 11, "Player 2 wins with %d points!", player2.getScore());
            }
            else
            {
                mvprintw(maxY / 2 + 1, maxX / 2 - 3, "It's a tie!");
            }
        }

        refresh();
    }

    /**
     * गेम लूप चलाएं
     */
    void run()
    {
        // इनपुट हैंडलिंग के लिए अलग थ्रेड शुरू करें
        std::thread inputThread([this]()
                                { this->processInput(); });

        // मुख्य गेम लूप
        while (!gameOver)
        {
            update();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }

        // अंतिम स्क्रीन रेंडर करें और 3 सेकंड के लिए इंतजार करें
        render();
        std::this_thread::sleep_for(std::chrono::seconds(3));

        // इनपुट थ्रेड के समाप्त होने का इंतजार करें
        inputThread.join();
    }
};

/**
 * मुख्य प्रोग्राम
 */
int main()
{
    // रैंडम नंबर जनरेटर इनिशियलाइज़ करें
    srand(static_cast<unsigned>(time(nullptr)));

    // गेम ऑब्जेक्ट बनाएं और चलाएं
    Game game;
    game.run();

    return 0;
}