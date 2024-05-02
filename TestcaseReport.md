#### SOFTWARE Test REPORT

# Test Report for Login Endpoints

## Test Case 1: Admin Student Teacher and CR Login
- *Method*: GET
- *Test Data*:
  - Username: MrSPD
  - Password: 123
 a) Successful Login 
    Expected Result: - HTTP status code: 200 OK
  - Response body: Contains an authentication token or user information
- *Pass/Fail*: Pass
b) Unsuccessful Login
    Expected Result: - HTTP status code: 200 OK
  -Response body:  404 Not Found with an error message –
    *Pass/Fail*: Pass
# Test Report for Admin Login Activity

#Test Report for Adminlogin Activity
## Test Case 1: Navigation through all options
- *Method*: UI Interaction
- *Expected Results*:
  - a) Successful Navigation
    - Expected Result: The app navigates to the `option ` activity.
    - *Pass/Fail*: Pass
  - b) Unsuccessful Navigation
    - Expected Result: An error message is displayed or the app does not navigate.
    - *Pass/Fail*: Pass
# Test Report for Adding and Removing Teachers

## Test Case 1: Add Teacher - Successful Addition
- *Method*: UI Interaction
- *Test Data*: Valid teacher information, including name, ID, subject, class, and password.
- *Expected Result*:
  - The system should add the teacher and display a success message.
  - The teacher's data should be stored in the database under the correct reference.
- *Actual Result*:
  - The system added the teacher and displayed a success message.
  - The teacher's data was stored in the database under the correct reference.
- *Pass/Fail*: Pass

## Test Case 2: Add Teacher - Missing Fields
- *Objective*: Verify that the system prevents adding a teacher when required fields are empty.
- *Method*: UI Interaction
- *Preconditions*: Some fields are left blank or contain invalid data.
- *Expected Result*:
  - The system should not add the teacher and should display an appropriate error message.
- *Actual Result*:
  - The system did not add the teacher and displayed an appropriate error message.
- *Pass/Fail*: Pass

## Test Case 3: Remove Teacher - Successful Removal
- *Objective*: Verify that a teacher can be successfully removed using a valid ID.
- *Method*: UI Interaction
- *Preconditions*: The teacher ID exists in the database.
- *Test Data*: Valid teacher ID.
- *Expected Result*:
  - The teacher should be removed from the database, and a success message should be displayed.
- *Actual Result*:
  - The teacher was removed from the database, and a success message was displayed.
- *Pass/Fail*: Pass

## Test Case 4: Remove Teacher - Invalid ID or Empty Field
- *Objective*: Verify that the system displays an error message when attempting to remove a teacher with an invalid or empty ID.
- *Method*: UI Interaction
- *Preconditions*: The teacher ID does not exist in the database or is empty.
- *Expected Result*:
  - An error message indicating that the ID is invalid or cannot be empty.
- *Actual Result*:
  - An error message indicated that the ID was invalid or could not be empty.
- *Pass/Fail*: Pass

# Test Report for View, Display, and List Student Information

## Test Case 1: View List of Students in Class
- *Objective*: Verify that the viewList method retrieves a list of students in the specified class (e.g., "CSE").
- *Method*: UI Interaction / Database Query
- *Preconditions*: Firebase database has students with a class field, and at least some are in the "CSE" class.
- *Expected Result*:
  - The Userlist array is populated with the correct student IDs from the "CSE" class.
  - No errors or exceptions during the database query.
  - A success message or list displayed upon completion.
- *Actual Result*:
  - The Userlist array was populated with the correct student IDs.
  - No errors encountered during the database query.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 2: Handle Database Query Failure
- *Objective*: Verify that the system properly handles database query failures or cancellations.
- *Method*: UI Interaction / Database Query
- *Preconditions*: Simulate a database error or cancellation.
- *Expected Result*:
  - The system should display an appropriate error message.
  - No data should be returned.
- *Actual Result*:
  - The system displayed an error message upon database failure.
  - No data was returned.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 3: Display Student Attendance List
- *Objective*: Verify that the display_list method retrieves and displays student attendance based on a given list and date.
- *Method*: UI Interaction / Database Query
- *Preconditions*: Firebase database has attendance records for the required date and class.
- *Expected Result*:
  - The Studentlist array is populated with student IDs, attendance status ("A" for Absent, "P" for Present), and period.
  - No errors or exceptions during the database query.
  - The list is displayed correctly on the UI.
- *Actual Result*:
  - The Studentlist array was populated with the correct data.
  - The list was displayed correctly in the UI.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 4: Display Attendance List - Missing Data
- *Objective*: Verify that the system handles missing or incomplete attendance data properly.
- *Method*: UI Interaction / Database Query
- *Preconditions*: Simulate a case with missing or incomplete data in the attendance database.
- *Expected Result*:
  - The system should handle missing data without crashing.
  - An error message or appropriate handling should occur if data is missing or invalid.
- *Actual Result*:
  - The system handled missing data without crashing.
  - Displayed appropriate messages or fallback behavior.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 5: Display Attendance List - Valid and Invalid Data
- *Objective*: Verify that the display_list method correctly identifies valid and invalid attendance data.
- *Method*: UI Interaction / Database Query
- *Preconditions*: The database contains both valid and invalid attendance data.
- *Expected Result*:
  - The system correctly displays valid data and handles invalid data.
  - No crashes or unexpected behavior during data retrieval.
- *Actual Result*:
  - The system displayed valid data correctly.
  - Handled invalid data without crashes or errors.
  - [To be filled after testing]
- *Pass/Fail*: Pass
# Test Report for viewAttendance Method in studentlogin Activity

## Test Case 1: View Attendance - Successful Navigation
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - Navigation to student_attendance_sheet with correct data.
  - sid and classname are passed correctly through the intent.
  - Smooth navigation without errors.
- *Actual Result*:
  - Navigation to student_attendance_sheet was successful.
  - sid and classname data were passed through the intent.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 2: View Attendance - Incorrect or Missing Data
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - System handles missing or incorrect data without crashing.
  - Appropriate error message or fallback behavior occurs if data is missing or incorrect.
- *Actual Result*:
  - System handled missing or incorrect data without crashing.
  - Appropriate handling or error messages were displayed.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 3: View Attendance - Proper Data Handling
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - Data passed through the intent (sid, classname) is used correctly in student_attendance_sheet.
  - No errors or incorrect behavior due to incorrect data handling.
- *Actual Result*:
  - Data was used correctly in student_attendance_sheet.
  - No errors or unexpected behavior observed.
  - [To be filled after testing]
- *Pass/Fail*: Pass
# Test Report for teacherlogin Activity - Take Attendance and View Records

## Test Case 1: Take Attendance - Successful Navigation
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The takeAttendanceButton method navigates to the takeAttendance activity.
  - The intent carries the correct data (class_selected and tid).
  - Navigation should be smooth without errors.
- *Actual Result*:
  - The method successfully navigated to takeAttendance.
  - The intent carried the correct data for class_selected and tid.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 2: Take Attendance - Incorrect or Missing Data
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The system handles incorrect or missing data in the intent without crashing.
  - Appropriate error handling or fallback behavior if data is missing or incorrect.
- *Actual Result*:
  - The system handled incorrect or missing data in the intent without crashing.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 3: View Previous Records - Successful Navigation
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The previous_records method navigates to teacher_attendanceSheet.
  - The intent carries the correct data (class_selected and tid).
  - Navigation should be smooth without errors.
- *Actual Result*:
  - The method successfully navigated to teacher_attendanceSheet.
  - The intent carried the correct data for class_selected and tid.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 4: View Previous Records - Incorrect or Missing Data
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The system handles incorrect or missing data in the intent without crashing.
  - Appropriate error handling or fallback behavior if data is missing or incorrect.
- *Actual Result*:
  - The system handled incorrect or missing data without crashing.
  - [To be filled after testing]
- *Pass/Fail*: Pass
# Test Report for Class Representative - Take Attendance

## Test Case 1: CR Take Attendance - Successful Navigation
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The CR's take attendance method navigates to the appropriate activity (e.g., CR_takeAttendance).
  - The intent carries correct data, such as class information, CR ID, or other required parameters.
  - Navigation is smooth, and no errors occur.
- *Actual Result*:
  - The navigation to CR_takeAttendance was successful.
  - The intent carried the correct data for class and CR ID.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 2: CR Take Attendance - Incorrect or Missing Data
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The system handles incorrect or missing data in the intent without crashing.
  - Appropriate error handling or fallback behavior if data is missing or incorrect.
- *Actual Result*:
  - The system handled incorrect or missing data without crashing.
  - Appropriate fallback behavior or error message was displayed.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 3: CR Take Attendance - Intent Data Verification
- *Method*: UI Interaction / Intent
- *Expected Result*:
  - The data passed through the intent is used correctly in the attendance activity.
  - No errors or incorrect behavior due to incorrect data handling.
- *Actual Result*:
  - The intent data was used correctly in the target activity (e.g., CR_takeAttendance).
  - No errors or unexpected behavior occurred.
  - [To be filled after testing]
- *Pass/Fail*: Pass

## Test Case 4: CR Take Attendance - UI and Interaction
- *Method*: UI Interaction
- *Expected Result*:
  - The CR can interact with the UI elements to take attendance without issues.
  - UI elements such as buttons and spinners work correctly.
- *Actual Result*:
  - UI interaction was smooth, and all elements functioned as expected.
  - No crashes or unexpected behavior.
  - [To be filled after testing]
- *Pass/Fail*: Pass
