#include <bits/stdc++.h>
//https://www.codingninjas.com/studio/guided-paths/oops-in-c/
// importing hero2 class which we can define in other file
#include "hero2.cpp"
using namespace std;

// hero type ki ek class bn chuki hai
class Hero
{

private:
    int health;

public:
    // properties
    char name[100];
    char level;

    // getter
    int getHealth()
    {
        return health;
    }

    // setter
    void setHealth(int h)
    {
        health = h;
    }

    //parametrised constructor
    Hero(int health,char level)
    {
        //keyword this is just a pointer to the current object
        this->level=level;
        this->health=health;
    }

    //making our own copy constructor
    Hero(Hero &temp)
    {
        this->health=temp.health;
        this->level=temp.level;
    }
};
int main()
{
    // creation of object using static allocation
    Hero h1(20,'A');
    Hero2 h2;

    // initialising values to the properties
    h1.level = 'k';

    // initialising values to the properties using setter
    h1.setHealth(50);

    // accessing properties
    cout << "Level is : " << h1.level << endl;

    // accessing properties of private using getter
    cout << "Health is : " << h1.getHealth() << endl;

    cout << "size :" << sizeof(h1) << endl;

    // creation of object using dynamic allocation
    Hero *h3 = new Hero(30,'B');
    // initialising values to the properties using setter in dynamic object
    h3->setHealth(90);
    // accessing dynamic object properties of private using getter
    cout << "Health is : " << (*h3).getHealth() << endl;
    // or another way is
    cout << "Health is : " << h3->getHealth() << endl;

    //creating object with parametrised constructor
    Hero h4(40,'C'); 

    //copy constructor
    //it will give all the value of h4 in h5
    Hero h5(h4);

    return 0;
}