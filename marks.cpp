#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> exam = {
    {"CT1", 20},
    {"CT2", 20},
    {"Internal", 10},
    {"Endsems", 50},
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
    unordered_map<string, unordered_map<string, int>> mp;
    //unordered_map<string, float> att_perc; //stores marks percentage for each student
    SubjectClass(string sb, string sc, string rollprefix, int rollrange){
        sub = sb;
        sec = sc;
        for(int i = 1; i<=rollrange; i++){
            string rollNo = giveRoll(rollprefix, i);
            unordered_map<string,int> m;
            for(auto it: exam){
                m[it.first]=0;
            }
            mp[rollNo] = m;
        }
    }
    void getMarks(string rollno, string exam){ //print marks for an exam
        cout<<mp[rollno][exam];
        cout << endl;
    }
    void getMarksStats(string rollno){ //get Marks stats for a student
    int totalMarks=0;
        unordered_map<string, int> stu_mark = mp[rollno];
        for(auto i: stu_mark){
                totalMarks+=i.second;
            }
        cout<<"Marks Percentage: "<<totalMarks<<endl;
    }

    void markMarks(string rollno, string exam, int marks){ //mark marks for a student
        mp[rollno][exam] = marks;
    }
    
};


class Student {
public:
    string rollNo;
    unordered_map<string, SubjectClass*> subjects; //list of subjects student is enrolled in
    Student(string roll){
        rollNo = roll;
    }
    void displaySubjects(){
        for(auto i: subjects)
            cout << i.first << endl;
        cout << "\n";
    }
    void getExamMarks(string sub, string exam){
        SubjectClass* sc = subjects[sub];
        sc->getMarks(rollNo, exam);
    }
    void getMarksStats(string sub){
        SubjectClass* sc = subjects[sub];
        sc->getMarksStats(rollNo);
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
    void displayClasses(){
        for(auto i: subjects)
            cout << i.first << endl;
        cout << "\n";
    }
    void getExamMarks(string subj_class, string rollno, string exam){
        SubjectClass* sc = subjects[subj_class];
        sc->getMarks(rollno, exam);
    }
    void getMarksStats(string subj_class, string rollno){
        SubjectClass* sc = subjects[subj_class];
        sc->getMarksStats(rollno);
    }
    void markMarks(string subj_class, string rollno, string exam,int marks){
        SubjectClass* sc = subjects[subj_class];
        sc->markMarks(rollno, exam, marks);
    }
    
};

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