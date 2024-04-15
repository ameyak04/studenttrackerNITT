#include <bits/stdc++.h>
using namespace std;

class LoginSystem
{
protected:
    unordered_map<int, string> idPasswordMap;

public:
    // Constructor to initialize the idPasswordMap
    LoginSystem(const unordered_map<int, string> &map) : idPasswordMap(map) {}

    // Function to verify login credentials
    virtual bool verifyLogin(int id, const string &password) = 0;
};

class Student : public LoginSystem{
public:
    Student(const unordered_map<int, string> &map) : LoginSystem(map) {}

    bool verifyLogin(int id, const string &password) override
    {
        auto it = idPasswordMap.find(id);
        if (it != idPasswordMap.end() && it->second == password)
        {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "Student login successful." << endl;
            cout << endl;
            cout << endl;
            return true;
        }
        else
        {
            cout << "Invalid student ID or password." << endl;
            cout << endl;
            cout << endl;
            return false;
        }
    }
};

class Teacher : public LoginSystem{
public:
    Teacher(const unordered_map<int, string> &map) : LoginSystem(map) {}

    bool verifyLogin(int id, const string &password) override
    {
        auto it = idPasswordMap.find(id);
        if (it != idPasswordMap.end() && it->second == password)
        {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "Teacher login successful." << endl;
            cout << endl;
            cout << endl;
            return true;
        }
        else
        {
            cout << "Invalid teacher ID or password." << endl;
            cout << endl;
            cout << endl;
            return false;
        }
    }
};

int main(){
    // Creating maps of student and teacher IDs mapped with passwords
    unordered_map<int, string> studentMap = {
        {1234, "student123"},
        {5678, "student567"}};

    unordered_map<int, string> teacherMap = {
        {9876, "teacher987"},
        {5432, "teacher543"}};

    // Creating instances of Student and Teacher
    Student student(studentMap);
    Teacher teacher(teacherMap);

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\tWELCOME TO NIT TRICHY" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\tWELCOME TO OUR APP" << endl;
    cout << endl;
    cout << endl;
    cout << "PLEASE CONFIRM YOUR OCCCUPATION" << endl;
    cout << endl;
    cout << "1. TEACHER" << endl;
    cout << endl;
    cout << "2. STUDENT" << endl;
    cout << endl;
    cout << endl;
    cout << "ENTER YOUR CHOICE (1 or 2)";
    cout << endl;
    cout << endl;
    int input = 0;
    while (true)
    {
        cin >> input;
        cout << endl;
        cout << endl;
        cout << endl;
        if (input == 1 || input == 2)
        {
            if (input == 2)
            {
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "WELCOME STUDENT!!";
                cout << endl;
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "WLCOME TEACHER!!";
                cout << endl;
                cout << endl;
            }
            break;
        }
        else
            cout << "!!!!!! PLEASE SELECT VALID OPTION !!!!!!";
        cout << endl;
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "\t\tENTER YOUR ID AND PASSWORD TO VERIFY YOUR CREDENTIALS";

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    int id;
    string pass;

    cin >> id;
    cout << endl;
    cin >> pass;
    cout << endl;

    if (input == 1)
        teacher.verifyLogin(id, pass);
    else
        student.verifyLogin(id, pass);

    // Verifying logins
    // student.verifyLogin(1234, "student123"); // Correct student credentials
    // teacher.verifyLogin(9876, "teacher123"); // Incorrect teacher password

    return 0;
}