#include <iostream>
#include <string>
using namespace std;

int main() {

    int totalCourses;

    string courseName[20];
    string grade[20];
    double credit[20];

    double totalPoints = 0;
    double totalCredits = 0;

    cout << "====== CGPA CALCULATOR ======" << endl;
    cout << "Enter total number of courses: ";
    cin >> totalCourses;

    for (int i = 0; i < totalCourses; i++) {

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courseName[i];

        cout << "Enter grade (A, A-, B+, B, C+, C, D, F): ";
        cin >> grade[i];

        cout << "Enter credit hours: ";
        cin >> credit[i];

        double gradePoint = 0;

        if (grade[i] == "A")
            gradePoint = 4.0;
        else if (grade[i] == "A-")
            gradePoint = 3.7;
        else if (grade[i] == "B+")
            gradePoint = 3.3;
        else if (grade[i] == "B")
            gradePoint = 3.0;
        else if (grade[i] == "C+")
            gradePoint = 2.3;
        else if (grade[i] == "C")
            gradePoint = 2.0;
        else if (grade[i] == "D")
            gradePoint = 1.0;
        else if (grade[i] == "F")
            gradePoint = 0.0;
        else
            cout << "Invalid grade! 0 points counted.\n";

  
        totalPoints += gradePoint * credit[i];
        totalCredits += credit[i];
    }

    double semesterGPA = totalPoints / totalCredits;

    char choice;
    double finalCGPA = semesterGPA;

    cout << "\nDo you have previous CGPA? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        double oldCGPA, oldCredits;

        cout << "Enter previous CGPA: ";
        cin >> oldCGPA;

        cout << "Enter previous total credits: ";
        cin >> oldCredits;

        double oldPoints = oldCGPA * oldCredits;
        finalCGPA = (oldPoints + totalPoints) / (oldCredits + totalCredits);
    }

    cout << "\n====== RESULT ======" << endl;

    for (int i = 0; i < totalCourses; i++) {
        cout << courseName[i]
             << " | Grade: " << grade[i]
             << " | Credits: " << credit[i] << endl;
    }

    cout << "\nSemester GPA: " << semesterGPA << endl;
    cout << "Overall CGPA: " << finalCGPA << endl;
    cout << "====================" << endl;

    return 0;
}
