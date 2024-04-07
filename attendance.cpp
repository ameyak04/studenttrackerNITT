#include <sqlite3.h>
#include<bits/stdc++.h>
using namespace std;

class AttendanceDatabase {
private:
    sqlite3* db;

public:
    AttendanceDatabase(const string& dbName) {
        int rc = sqlite3_open(dbName.c_str(), &db);
        if (rc) {
            cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            exit(1);
        }
    }

    ~AttendanceDatabase() {
        sqlite3_close(db);
    }

    void createAttendanceTable(int monthLength, int classStrength, string rollNoPrefix) {
        const char* createTableSQL = "CREATE TABLE IF NOT EXISTS attendance (roll_no INTEGER PRIMARY KEY)";
        executeQuery(createTableSQL);
        for (int i = 1; i <= monthLength; ++i) {
            string columnName = "day_" + to_string(i);
            string alterTableSQL = "ALTER TABLE attendance ADD COLUMN " + columnName + " INTEGER DEFAULT 0";
            executeQuery(alterTableSQL);
        }
        for(int i = 1; i<= classStrength; i++){
            string x;
            if(i < 10)  x = "00";
            else if (i >= 10 && i < 100)  x = "0";
            else    x = "";
            string rollNo = rollNoPrefix + x + to_string(i);
            string insertRollNoSQL = "INSERT INTO attendance(roll_no) VALUES(" + rollNo + ");";
            executeQuery(insertRollNoSQL);
        }
    }

    void dropTable(){
        const char* ok = "DROP TABLE attendance";
        executeQuery(ok);
    }

    void markAttendance(int rollNo, int day, int attendance) {
        string columnName = "day_" + to_string(day);
        string updateSQL = "UPDATE attendance SET " + columnName + " = " + to_string(attendance) +
                                " WHERE roll_no = " + to_string(rollNo);
        executeQuery(updateSQL);
    }

    void markAttendanceToday(int day,int numStart,int numEnd){
        for(int i=numStart;i<=numEnd;i=i+2){
            cout<<"Mark 1 if "<<i<<" is present else -1"<<endl;
            int temp;
            cin>>temp;
            markAttendance(i,day,temp);
        }
    }

    void calculateAttendancePercentage(int rollNo, int numDays) {
        double totalDays = 0.0;
        double presentDays = 0.0;
        double absentDays = 0.0;
        for (int i = 1; i <= numDays; ++i) {
            string columnName = "day_" + to_string(i);
            string selectSQL = "SELECT " + columnName + " FROM attendance WHERE roll_no = " + to_string(rollNo);
            int attendance;
            if (executeSelectQuery(selectSQL, attendance)) {
                if (attendance == 1){
                    presentDays += 1.0;    
                    totalDays += 1.0;           
                }else if(attendance == -1.0){
                    absentDays += 1.0;
                    totalDays += 1.0;
                }
            }
        }
        double value = (presentDays / totalDays) * 100.0;
        cout<<rollNo<<" your attendance percentage is "<<value<<"% "<<endl;
    }

    void displayTable() {
        cout << setw(10)<<"Roll No  "<< " ";
        for (int i = 1; i <= 30; ++i) {
            cout <<setw(3) << i << " ";
        }
        cout << endl;
        const char* sql = "SELECT * FROM attendance";
        sqlite3_stmt *stmt;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << setw(10) << sqlite3_column_int(stmt, 0) << " ";
             for (int i = 1; i <= 30; ++i) {
                cout << setw(3) << sqlite3_column_int(stmt, i) << " "; // Day_1, Day_2, ..., Day_30
            }
            cout << endl;
        }
        sqlite3_finalize(stmt);
        } 
        else {
            cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        }
    }

private:
    void executeQuery(const string& sql) {
        char* errMsg;
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL error: " << errMsg << endl;
            sqlite3_free(errMsg);
        }
    }

    bool executeSelectQuery(const string& sql, int& result) {
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                result = sqlite3_column_int(stmt, 0);
                sqlite3_finalize(stmt);
                return true;
            }
        }
        sqlite3_finalize(stmt);
        return false;
    }
};

int main() {
    AttendanceDatabase db("attendance.db");
    db.dropTable();
    db.createAttendanceTable(30,40,"106122");
    db.markAttendance(106122012,5,1);
    db.markAttendance(106122010, 7, 1);
    db.markAttendance(10612205, 1, 1);
    // Display the table
    //cout<<db.calculateAttendancePercentage(106122012,10);
    db.markAttendanceToday(3,106122012,106122012);
    //db.displayTable();
    db.calculateAttendancePercentage(106122012,10);
    return 0;
}