#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main()
{
    int number_of_semesters, number_of_courses, credit_houres, semester_credits, grade_100;
    double grade_4, GPA, CGPA_, CGPA;
    string course, grade_A;
    vector <string> COURSES, COURSES_GRADES;
    vector <int> NUMBER_OF_COURSES_PER_SEMESTER;
    vector <double> GPAs;
    COURSES.push_back(" ");
    COURSES_GRADES.push_back("X");
    NUMBER_OF_COURSES_PER_SEMESTER.push_back(0);


    cout << "=====================" << endl;
    cout << "   CGPA Calculator   " << endl;
    cout << "=====================" << endl << endl;


    cout << "Enter the number of semesters: ";
    cin >> number_of_semesters;

    for(int i = 1 ; i <= number_of_semesters ; i++){
        semester_credits = 0;
        vector <string> courses_names;
        vector <int> courses_credit_houres;
        vector <double> courses_grades;
        cout << "\nEnter the number of courses for semester " << i << ": ";
        cin >> number_of_courses;
        NUMBER_OF_COURSES_PER_SEMESTER.push_back(number_of_courses);
        for(int j = 1 ; j <= number_of_courses ; j++){
            cout << "\nEnter course "<< j << " information: "<< endl;

            cout << "Name: ";
            cin >> course;
            courses_names.push_back(course);
            COURSES.push_back(course);

            cout << "Number of Credit Houres: ";
            cin >> credit_houres;
            courses_credit_houres.push_back(credit_houres);
            semester_credits += credit_houres;

            cout << "Grade (0-100): ";
            cin >> grade_100;

            while(grade_100 < 0 || grade_100 > 100){
                cout << "Invalid input! Please enter a grade between 0 and 100." << endl;
                cout << "Grade (0-100): ";
                cin >> grade_100;
            }
            if(grade_100 < 60){
                grade_4 = 0;
                grade_A = "F";
            }
            else if(grade_100 < 64){
                grade_4 = 1;
                grade_A = "D";
            }
            else if(grade_100 < 67){
                grade_4 = 1.3;
                grade_A = "D+";
            }
            else if(grade_100 < 70){
                grade_4 = 1.7;
                grade_A = "C-";
            }
            else if(grade_100 < 73){
                grade_4 = 2;
                grade_A = "C";
            }
            else if(grade_100 < 76){
                grade_4 = 2.3;
                grade_A = "C+";
            }
            else if(grade_100 < 80){
                grade_4 = 2.7;
                grade_A = "B-";
            }
            else if(grade_100 < 84){
                grade_4 = 3;
                grade_A = "B";
            }
            else if(grade_100 < 89){
                grade_4 = 3.3;
                grade_A = "B+";
            }
            else if(grade_100 < 93){
                grade_4 = 3.7;
                grade_A = "A-";
            }
            else if(grade_100 < 97){
                grade_4 = 4;
                grade_A = "A";
            }
            else{
                grade_4 = 4;
                grade_A = "A+";
            }
            courses_grades.push_back(grade_4);
            COURSES_GRADES.push_back(grade_A);
        }
        GPA = 0;
        for(int j = 0 ; j < number_of_courses ; j++){
            GPA += (double)courses_credit_houres[j] * courses_grades[j];
        }
        GPA /= (double)semester_credits;
        GPAs.push_back(GPA);
        CGPA_ = 0;
        for(int j = 0 ; j < i ; j++){
            CGPA_ += GPAs[j];
        }
        CGPA = CGPA_/i;
        cout << endl;
        cout << "Semester GPA: " << GPAs[i-1] << endl;
        cout << "Cumulative GPA: " << CGPA << endl;
    }

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       SUMMARY REPORT       " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    for(int i=1 ; i <= number_of_semesters ; i++){
        cout << "         SEMESTER " << i << "         "<< endl;
        cout << "============================" << endl;
        cout << "|     Course     |  Grade  |" << endl;
        cout << "|================|=========|" << endl;
        for(int j=1 ; j <= NUMBER_OF_COURSES_PER_SEMESTER[i] ; j++){
            cout << "| " << setw(15) << left << COURSES[j] << "|" << setw(9) << left << COURSES_GRADES[j] << "|" << endl;
            cout << "|----------------|---------|" << endl;
        }
        cout << "|  Semester GPA  |" << setw(9) << left << GPAs[i-1] << "|" << endl;
        cout << "============================" << endl << endl;
    }
    cout << "============================" << endl;
    cout << "| Cumulative GPA |" << setw(9) << left << CGPA << "|" << endl;
    cout << "============================" << endl;

    return 0;
}
