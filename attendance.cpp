#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> months = { //stores number of days in each month
    {"Jan", 31},
    {"Feb", 28},
    {"Mar", 31},
    {"Apr", 30},
    {"May", 31},
    {"Jun", 30},
    {"Jul", 31},
    {"Aug", 31},
    {"Sep", 30},
    {"Oct", 31},
    {"Nov", 30},
    {"Dec", 31},
};

string giveRoll(string pref, int n){
    string x = to_string(n);
    if(x.size() == 1)
        return pref+"00"+x;
    else if(x.size() == 2)
        return pref+"0"+x;
    return pref+x;
}

class SubjectClass {
public:
    string sub, sec;
    map<string, unordered_map<string, vector<int>>> mp;           //to store the attendance info. for each student in a class
    SubjectClass(string sb, string sc, string rollprefix, int rollrange){   //constr. to initialize the map
        sub = sb;
        sec = sc;
        for(int i = 1; i<=rollrange; i++){
            string rollNo = giveRoll(rollprefix, i);
            unordered_map<string,vector<int>> m;
            for(auto it: months){
                vector<int> v(it.second, 0);
                m[it.first] = v;
            }
            mp[rollNo] = m;
        }
    }
    void getAttendance(string rollno, string month){            //print attendance for a month
        unordered_map<string, vector<int>> stu_att = mp[rollno];
        for(auto i: stu_att[month])
            cout << i << " ";
        cout << endl;
    }
    void getAttendanceStats(string rollno){                     //get attendance stats for a student
        float present = 0, absent = 0;
        unordered_map<string, vector<int>> stu_att = mp[rollno];
        for(auto i: stu_att){
            for(auto j: i.second){
                if(j == 1)
                    present++;
                if(j == -1)
                    absent++;
            }
        }
        float total = present + absent;
        cout << "Attended: " << present << endl;
        cout << "Absent: " << absent << endl;
        cout << "Attendance Percentage: " << (present*100)/total << endl;
        if(present/total < 0.75)
            cout << "More classes needed to meet 75% criteria: " << 3*absent-present << "\n\n";
    }

    void markAttendance(string rollno, string month, int date, int status){ //mark attendance for a student
        mp[rollno][month][date - 1] = status;
    }

    void takeDayAttendance(string month, int date){                        //mark attendance for every student on a particular date
        cout << "Enter 1 for present, -1 for absent.\n";
        int st;
        for(auto i: mp){
            string rno = i.first;
            cout << rno << ": ";
            cin >> st;
            cout << endl;
            markAttendance(rno, month, date, st);
        }
    }
};


class Student {
public:
    string rollNo;
    unordered_map<string, SubjectClass*> subjects;      //list of subjects student is enrolled in
    Student(string roll){
        rollNo = roll;
    }
    void displaySubjects(){                             //displays the list of subjects student is enrolled in
        for(auto i: subjects)
            cout << i.first << endl;
        cout << "\n";
    }
    void getMonthAttendance(string sub, string month){ //get the attendance info. for a month
        SubjectClass* sc = subjects[sub];
        sc->getAttendance(rollNo, month);
    }
    void getAttendanceStats(string sub){                //get overall attendance stats
        SubjectClass* sc = subjects[sub];
        sc->getAttendanceStats(rollNo);
    }
};

class Teacher {
public:
    string name;
    string teacher_id;
    unordered_map<string, SubjectClass*> subjects; //eg. SE_CSE-B -> SE_CSE-B object
    Teacher(string tid, string tname){
        teacher_id = tid;
        name = tname;
    }
    void displayClasses(){      //to show list of subjects the teacher teaches
        for(auto i: subjects)
            cout << i.first << endl;
        cout << "\n";
    }
    void getMonthAttendance(string subj_class, string rollno, string month){ //get the attendance info. for a month for a student
        SubjectClass* sc = subjects[subj_class];
        sc->getAttendance(rollno, month);
    }
    void getAttendanceStats(string subj_class, string rollno){              //get overall attendance stats for a student
        SubjectClass* sc = subjects[subj_class];
        sc->getAttendanceStats(rollno);
    }
    void markAttendance(string subj_class, string rollno, string month, int date, int status){ //mark att. for a student on a particular date
        SubjectClass* sc = subjects[subj_class];
        sc->markAttendance(rollno, month, date, status);
    }
    void takeTodaysAttendance(string subj_class, string month, int date){ //mark att. for all students on a particular date
        SubjectClass* sc = subjects[subj_class];
        sc->takeDayAttendance(month, date);
    }
    
};

//global variables to store the already created Teacher and Student objects 
unordered_map<string, Student*> student_list;
unordered_map<string, Teacher*> teacher_list;

class Admin {
public:
    void createClass(string sub, string sec, string tid, string tname, string roll_pref, int roll_range){  
        SubjectClass *obj = new SubjectClass(sub, sec, roll_pref, roll_range);
        for(int i = 1; i<=roll_range; i++){
            
            string rollno = giveRoll(roll_pref, i);
            if(student_list.find(rollno) != student_list.end())
                student_list[rollno]->subjects[sub] = obj;
            else{
                Student* s = new Student(rollno);
                s->subjects[sub] = obj;
                student_list[rollno] = s;
            }
        }
        if(teacher_list.find(tid) != teacher_list.end())
            (teacher_list[tid])->subjects[sub+"_"+sec] = obj;
        else{
            Teacher* T = new Teacher(tid, tname);
            T->subjects[sub+"_"+sec] = obj;
            teacher_list[tid] = T;
        }
    }
};

int main(){
    while(true){
        cout << "1. Admin\n2. Teacher\n3. Student\n";
        int c;
        cin >> c;
        if(c == 1){
            cout << "To create a class, enter subject, section, teacher ID, teacher name, roll no. prefix, roll no. range:\n";
            string sub, sec, tid, tname, roll_pref; 
            int roll_range;
            cin >> sub >> sec >> tid >> tname >> roll_pref;
            cin >> roll_range;
            Admin A;
            A.createClass(sub, sec, tid, tname, roll_pref, roll_range);
            cout << "Class created.\n\n";
        }
        else if(c == 2){
            cout << "Enter teacher ID:";
            string tid;
            cin >> tid;
            
            Teacher* T = teacher_list[tid];
            cout << "\nName: " << T->name << endl;
            cout << "Classes taught:\n";
            T->displayClasses();
            cout << "1. View attendance\n2. Mark attendance\n";
            int c1;
            cin >> c1;
            switch(c1){
                case 1: {
                    cout << "Enter subject_section:";
                    string su, rno;
                    cin >> su;
                    cout << "Enter roll number:";
                    cin >> rno;
                    cout << "1. View attendance for a month.\n2. View attendance stats.\n";
                    int c2;
                    cin >> c2;
                    switch(c2){
                        case 1:{
                            string m;
                            cout << "Enter month:";
                            cin >> m;
                            T->getMonthAttendance(su, rno, m);
                            break;
                        }
                        case 2: {
                            T->getAttendanceStats(su, rno);
                            break;
                        }
                        default: cout << "Incorrect choice!" << endl;
                    }
                    break;
                }

                case 2:{
                    cout << "Enter subject_section:";
                    string su, rno, m;
                    int status, date;
                    cin >> su;
                    cout << "Enter roll number, month, date:\n";
                    cin >> rno >> m >> date;
                    cout << "Enter 1 for present, -1 for absent:";
                    cin >> status;
                    T->markAttendance(su, rno, m, date, status);
                    cout << "Marked.\n\n";
                    break;
                }

                default: cout << "Incorrect choice!\n\n";
            }
        }
        else if(c == 3){
            string sub, rno;
            cout << "Enter roll number:";
            cin >> rno;
            Student* S = student_list[rno];
            cout << "\nSubjects taken:\n";
            S->displaySubjects();
            cout << "1. View attendance for a month.\n2. View attendance stats.\n";
            int c3;
            cin >> c3;
            cout << "Enter subject:";
            cin >> sub;
            switch(c3){
                case 1: {
                    string m;
                    cout << "Enter month:";
                    cin >> m;
                    S->getMonthAttendance(sub, m);
                    break;
                }
                case 2: {
                    S->getAttendanceStats(sub);
                }
            }
        }
        else
            cout << "Incorrect choice!" << endl;
        cout << "Play again? 1.Yes 2.No\n";
        cin >> c;
        if(c == 1) continue;
        else break;
    }
    return 0;
}
