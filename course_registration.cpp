#include <bits/stdc++.h>
using namespace std;

class Course {
private:
    string name;
    int credits;

public:
    Course(string name, int credits) : name(name), credits(credits) {}

    string getName() const {  //getter function to get name 
        return name;
    }

    int getCredits() const {   //getter function to get credits
        return credits;
    }
};


class Department {
private:
    string name;
    vector<Course> courses;

public:
    Department(string name) : name(name) {}

    string getName() const {   //getter function to get name 
        return name;
    }

    void addCourse(Course course) {
        courses.push_back(course);
    }

    const vector<Course>& getCourses() const {
        return courses;
    }

    void availableCourses() const {
        cout << "Courses offered in " << name << ":" << endl;
        cout << setw(30) << "NAME OF COURSES" << "\t\t" << setw(30) << "NUMBER OF CREDITS" << endl;
        for (const Course& course : courses) {
            cout << setw(30) << course.getName() << "\t\t" << setw(30) << course.getCredits() << endl;
        }
    }
};


class Registration {
public:
    vector<Department> departments;
    int minCredits;
    int maxCredits;

public:
    Registration(int minCredits, int maxCredits) : minCredits(minCredits), maxCredits(maxCredits) {}

    void addDepartment(Department department) {
        departments.push_back(department);
    }

    void displayDepartments() const {   //display all available departments
        cout << "Available Departments:" << endl;
        for (const Department& department : departments) {
            cout << department.getName() << endl;
            department.availableCourses();
            cout << endl;
        }
    }

    bool registerCourses(Department& department) const {    //register courses for a department
        department.availableCourses();
        vector<int> cred;
        for (const Course& course : department.getCourses()) {
            cred.push_back(course.getCredits());
        }
        cout << "CHOOSE COURSES (Enter course numbers separated by spaces, -1 to finish): ";
        int temp = 0;
        int sum = 0;
        while (true) {
            cin >> temp;
            if (temp == -1) break;
            if (temp < 0 || temp >= cred.size()) {
                cout << "Invalid course number, please try again." << endl;
                continue;
            }
            sum += cred[temp];
        }
        if (sum >= minCredits && sum <= maxCredits) {
            return true;
        }
        return false;
    }
};

int main() {
    Registration registration(12, 20);
    Department cse("CSE");
    cse.addCourse(Course("Data Structures", 4));
    cse.addCourse(Course("Algorithms", 5));
    cse.addCourse(Course("Computer Networks", 4));
    cse.addCourse(Course("Software Engeneering",3));
    cse.addCourse(Course("Design Thinking", 3));
    cse.addCourse(Course("Operating Systems",4));

    Department eee("EEE");
    eee.addCourse(Course("Electrical Circuits", 4));
    eee.addCourse(Course("Power Systems", 5));

    Department ece("ECE");
    ece.addCourse(Course("Digital Electronics", 4));
    ece.addCourse(Course("Signal Processing", 5));

    registration.addDepartment(cse);
    registration.addDepartment(eee);
    registration.addDepartment(ece);


    registration.displayDepartments();


    cout << "SELECT THE DEPARTMENT (Enter department number): ";
    int index;
    cin >> index;
    if (index < 1 || index > registration.departments.size()) {
        cout << "Invalid department number." << endl;
        return 1;
    }
    Department& selectedDepartment = registration.departments[index - 1];
    bool success = registration.registerCourses(selectedDepartment);
    if (success) {
        cout << "SUCCESSFUL REGISTRATION" << endl;
    } else {
        cout << "UNSUCCESSFUL REGISTRATION" << endl;
    }
    return 0;
}
