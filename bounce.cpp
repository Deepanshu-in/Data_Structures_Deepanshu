#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

struct Ball
{
    int xPosition;
    int yPosition;
    int xVelocity;
    int yVelocity;
    char symbol;

    void initialize(int screenWidth, int screenHeight)
    {
        xPosition = screenWidth / 2;
        yPosition = screenHeight / 3;
        xVelocity = (rand() % 2) * 2 - 1;
        yVelocity = 1;
        symbol = 'O';
    }

    bool update(const struct Paddle &paddle, int screenWidth, int screenHeight, int &score);

    void draw() const
    {
        attron(COLOR_PAIR(1));
        mvaddch(yPosition, xPosition, symbol);
        attroff(COLOR_PAIR(1));
    }

    void clear() const
    {
        mvaddch(yPosition, xPosition, ' ');
    }
};

struct Paddle
{
    int xPosition;
    int width;
    char symbol;

    void initialize(int screenWidth, int screenHeight)
    {
        xPosition = screenWidth / 2;
        width = 7;
        symbol = '=';
    }

    void move(int direction, int screenWidth)
    {
        int newPosition = xPosition + direction;
        int leftEdge = newPosition - width / 2;
        int rightEdge = newPosition + width / 2;

        if (leftEdge > 0 && rightEdge < screenWidth - 1)
        {
            xPosition = newPosition;
        }
    }

    void draw(int screenHeight) const
    {
        int paddleY = screenHeight - 2;
        int leftEdge = xPosition - width / 2;
        int rightEdge = xPosition + width / 2;

        attron(COLOR_PAIR(2));
        for (int i = leftEdge; i <= rightEdge; i++)
        {
            mvaddch(paddleY, i, symbol);
        }
        attroff(COLOR_PAIR(2));
    }

    int getYPosition(int screenHeight) const
    {
        return screenHeight - 2;
    }

    int getLeftEdge() const
    {
        return xPosition - width / 2;
    }

    int getRightEdge() const
    {
        return xPosition + width / 2;
    }
};

void drawBorder(int screenWidth, int screenHeight)
{
    attron(COLOR_PAIR(3));

    for (int i = 0; i < screenWidth; i++)
    {
        mvaddch(0, i, '-');
    }

    for (int i = 0; i < screenHeight; i++)
    {
        mvaddch(i, 0, '|');
        mvaddch(i, screenWidth - 1, '|');
    }

    attroff(COLOR_PAIR(3));
}

void displayGameInfo(int score, int lives, int screenHeight, int screenWidth)
{
    attron(COLOR_PAIR(4));

    mvprintw(1, 2, "Score: %d  Lives: %d", score, lives);
    mvprintw(screenHeight - 1, 2, "Use LEFT/RIGHT arrow keys to move, 'q' to quit");

    attroff(COLOR_PAIR(4));
}

void displayGameOver(int score, int screenWidth, int screenHeight)
{
    clear();

    attron(COLOR_PAIR(5) | A_BOLD);
    mvprintw(screenHeight / 2, screenWidth / 2 - 10, "GAME OVER - Final Score: %d", score);
    attroff(A_BOLD);
    mvprintw(screenHeight / 2 + 1, screenWidth / 2 - 10, "Press any key to exit");
    attroff(COLOR_PAIR(5));

    refresh();

    timeout(-1);
    getch();
}

void initializeNcurses()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    timeout(100);

    start_color();

    init_pair(1, COLOR_BLUE, COLOR_CYAN);
    init_pair(2, COLOR_GREEN, COLOR_CYAN);
    init_pair(3, COLOR_MAGENTA, COLOR_CYAN);
    init_pair(4, COLOR_YELLOW, COLOR_CYAN);
    init_pair(5, COLOR_RED, COLOR_CYAN);
    init_pair(6, COLOR_BLACK, COLOR_CYAN);

    bkgd(COLOR_PAIR(6));
}

bool Ball::update(const struct Paddle &paddle, int screenWidth, int screenHeight, int &score)
{
    clear();

    xPosition += xVelocity;
    yPosition += yVelocity;

    if (xPosition <= 0 || xPosition >= screenWidth - 1)
    {
        xVelocity = -xVelocity;
        xPosition += xVelocity;
    }

    if (yPosition <= 0)
    {
        yVelocity = -yVelocity;
        yPosition += yVelocity;
    }

    int paddleY = paddle.getYPosition(screenHeight);
    if (yPosition == paddleY && xPosition >= paddle.getLeftEdge() && xPosition <= paddle.getRightEdge())
    {
        yVelocity = -yVelocity;
        yPosition += yVelocity;
        score += 10;
    }

    if (yPosition >= screenHeight - 1)
    {
        return false;
    }

    draw();
    return true;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    initializeNcurses();

    int screenHeight, screenWidth;
    getmaxyx(stdscr, screenHeight, screenWidth);

    Ball ball;
    Paddle paddle;

    ball.initialize(screenWidth, screenHeight);
    paddle.initialize(screenWidth, screenHeight);

    bool gameRunning = true;
    int score = 0;
    int lives = 5;

    while (gameRunning && lives > 0)
    {
        clear();

        drawBorder(screenWidth, screenHeight);

        displayGameInfo(score, lives, screenHeight, screenWidth);

        paddle.draw(screenHeight);

        if (!ball.update(paddle, screenWidth, screenHeight, score))
        {
            lives--;
            if (lives > 0)
            {
                ball.initialize(screenWidth, screenHeight);
            }
        }

        refresh();

        int key = getch();
        if (key == 'q' || key == 'Q')
        {
            gameRunning = false;
        }
        else if (key == KEY_LEFT)
        {
            paddle.move(-2, screenWidth);
        }
        else if (key == KEY_RIGHT)
        {
            paddle.move(2, screenWidth);
        }
    }

    displayGameOver(score, screenWidth, screenHeight);

    endwin();

    return 0;
}