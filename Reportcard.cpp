#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class Student
{
private:
    string RollNo, Name, Grade;

public:
    Student() : RollNo(""), Name(""), Grade("") {}

    void setRollNo(const string &rollNo)
    {
        RollNo = rollNo;
    }
    void setName(const string &name)
    {
        Name = name;
    }
    void setGrade(const string &grade)
    {
        Grade = grade;
    }

    string getRollNo() const
    {
        return RollNo;
    }
    string getName() const
    {
        return Name;
    }
    string getGrade() const
    {
        return Grade;
    }
};

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    Student s;
    bool exit = false;
    while (!exit)
    {
        clearScreen();
        int val;
        cout << "-----------Welcome to student report card management system-------------" << endl;
        cout << "1. Report Card" << endl;
        cout << "2. Exit" << endl;
        cout << "---------------------------Enter Choice----------------------------------" << endl;
        cin >> val;

        if (val == 1)
        {
            clearScreen();
            string RollNo, name;
            cout << "Enter Roll no of the student: ";
            cin >> RollNo;
            cin.ignore(); // To clear the newline character from the buffer
            s.setRollNo(RollNo);

            cout << "Enter the name of the student: ";
            getline(cin, name);
            s.setName(name);

            int physics, chemistry, math, total;
            float avg;
            cout << "Enter marks in physics: ";
            cin >> physics;
            cout << "Enter marks in chemistry: ";
            cin >> chemistry;
            cout << "Enter marks in math: ";
            cin >> math;

            clearScreen();
            cout << "\t---------- Student Report Card ------------" << endl;
            total = physics + chemistry + math;
            cout << "Total marks: " << total << endl;
            avg = total / 3.0f;
            cout << "Average marks of the student: " << avg << endl;

            if (avg >= 90 && avg <= 100)
            {
                s.setGrade("A");
            }
            else if (avg >= 80 && avg < 90)
            {
                s.setGrade("B");
            }
            else if (avg >= 70 && avg < 80)
            {
                s.setGrade("C");
            }
            else if (avg >= 60 && avg < 70)
            {
                s.setGrade("D");
            }
            else
            {
                s.setGrade("Fail");
            }
            cout << "Grade of student: " << s.getGrade() << endl;

            ofstream out("student.txt", ios::app);
            out << s.getRollNo() << " " << s.getName() << " " << s.getGrade() << endl;
            out.close();
            cout << "------------ Your report card is saved --------" << endl;

#ifdef _WIN32
            Sleep(1000); // Windows sleep for 1 second
#else
            sleep(1); // Unix-based sleep for 1 second
#endif
        }
        else if (val == 2)
        {
            clearScreen();
            exit = true;
            cout << "Best of luck" << endl;

#ifdef _WIN32
            Sleep(5000); // Windows sleep for 5 seconds
#else
            sleep(5); // Unix-based sleep for 5 seconds
#endif
        }
    }
    return 0;
}
