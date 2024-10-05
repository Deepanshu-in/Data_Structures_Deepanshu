#include <bits/stdc++.h>
using namespace std;

// creating class teacher
class Teacher
{
    // properties or attributes
private:
    double salary;

public: // by default it is private
    string name;
    string dept;
    string subject;

    // creating constructor  (a class can have more than one constructors given if they have different parameters)
    // Teacher() // not parameterised constructor
    // {
    //     dept = "CSE"; // it will set all the objects default dept as CSE
    // }
    Teacher(string name, string dept, string subject, double salary) // parameterised constructor
    {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // custom copy constructor
    Teacher(Teacher &orgObj)
    {
        cout << "I am custom copy constructor" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    // destructor
    ~Teacher()
    {
        cout << "Hi, I delete everything...." << endl;
    }

    // methods or member functions
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    // setter for salary as it is private
    void setSalary(double s)
    {
        salary = s;
    }
    // getter for salary as it is private
    double getSalary()
    {
        return salary;
    }

    void getInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Dept : " << dept << endl;
        cout << "Subject : " << subject << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main()
{
    // creating an object of teacher
    // Teacher t1;
    // giving values
    // t1.name = "Deepanshu";
    // t1.dept = "CSE";
    // t1.subject = "Operating Systems";
    // t1.setSalary(25000);
    // cout << t1.getSalary() << endl;

    // calling constructor to initialize new object t2
    Teacher t2("Bhumi", "CSE", "DBMS", 30000);
    t2.getInfo();
    // copy constructor
    Teacher t3(t2);
    t3.getInfo();
    return 0;
}