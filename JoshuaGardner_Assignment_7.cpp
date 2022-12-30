/* Name: Joshua Gardner
Content: Using classes/member functions to calculate 2 students test scores etc
Date: 11/25/2020 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student_record //class constructors, member functions, friend function
{
public:
    Student_record();
    Student_record(int q1, int q2, int mid_exam, int fin_exam);
    int get_quiz_1();
    int get_quiz_2();
    int get_midterm_exam();
    int get_final_exam();
    void set_avg_score();
    void set_grade();
    double get_avg();
    char get_grade();
    void output(ostream& outs);
    friend void compare(Student_record student_1, Student_record student_2);

private: // member variables
    int quiz_1;
    int quiz_2;
    int midterm_exam;
    int final_exam;
    double avg_score;
    char final_grade;
};

int main()
{
    int scores_1[4], scores_2[4]; // input values/requests stored in arrays

    cout << "Please enter student_1 quiz_1 score: " << endl;
    cin >> scores_1[0];
    cout << "Please enter student_1 quiz_2 score: " << endl;
    cin >> scores_1[1];
    cout << "Please enter student_1 midterm score: " << endl;
    cin >> scores_1[2];
    cout << "Please enter student_1 Final_exam score: " << endl;
    cin >> scores_1[3];

    cout << "Please enter student_2 quiz_1 score: " << endl;
    cin >> scores_2[0];
    cout << "Please enter student_2 quiz_2 score: " << endl;
    cin >> scores_2[1];
    cout << "Please enter student_2 midterm score: " << endl;
    cin >> scores_2[2];
    cout << "Please enter student_2 Final_exam score: " << endl;
    cin >> scores_2[3];
    //constructor initialization and set function calls
    Student_record student_1(scores_1[0], scores_1[1], scores_1[2], scores_1[3]), student_2(scores_2[0], scores_2[1], scores_2[2], scores_2[3]);
    student_1.set_avg_score();
    student_2.set_avg_score();
    student_1.set_grade();
    student_2.set_grade();
    //output function calls
    cout << endl << "Student_1 results: " << endl;
    student_1.output(cout);

    cout << "Student_2 results: " << endl;
    student_2.output(cout);

    compare(student_1, student_2);

    return 0;
}
//constructor default
Student_record::Student_record(): avg_score(0.0), final_grade('E')
{

}
//constructor definition
Student_record::Student_record(int q1, int q2, int mid_exam, int fin_exam)
    {
        quiz_1 = q1;
        quiz_2 = q2;
        midterm_exam = mid_exam;
        final_exam = fin_exam;
    }
//member function that returns the quiz_1 member variable value
int Student_record::get_quiz_1()
{
    return quiz_1;
}
//member function that returns the quiz_2 member variable value
int Student_record::get_quiz_2()
{
    return quiz_2;
}
//member function that returns the midterm_exam member variable value
int Student_record::get_midterm_exam()
{
    return midterm_exam;
}
//member function that returns the final_exam member variable value
int Student_record::get_final_exam()
{
    return final_exam;
}
//member function that sets the avg_score member variable value
void Student_record::set_avg_score()
{
    double midterm_percent, fin_exam_percent;
    double quiz_percent, total_avg;
    quiz_percent = (((static_cast<double>(get_quiz_1()) + static_cast<double>(get_quiz_2())) / 40) * 100) * .4;
    midterm_percent = static_cast<double>(get_midterm_exam()) * .25;
    fin_exam_percent = static_cast<double>(get_final_exam()) * .35;
    total_avg = quiz_percent + midterm_percent + fin_exam_percent;
    avg_score = total_avg;
}
//member function that returns the avg_score member variable
double Student_record::get_avg()
{
    return avg_score;
}
//member function that sets the final_grade value = to a letter grade
void Student_record::set_grade()
{
    char grade;
    if (get_avg() > 89)
        grade = 'A';
    else if (get_avg() < 90 && get_avg() > 79)
        grade = 'B';
    else if (get_avg() < 80 && get_avg() > 69)
        grade = 'C';
    else if (get_avg() < 70 && get_avg() > 59)
        grade = 'D';
    else
        grade = 'F';
    final_grade = grade;
}
//member function that returns final_grade value
char Student_record::get_grade()
{
    return final_grade;
}
// member function that outputs member variables
void Student_record::output(ostream& outs)
{
    outs << "Quiz 1:       " << get_quiz_1() << endl;
    outs << "Quiz 2:       " << get_quiz_2() << endl;
    outs << "Midterm:      " << get_midterm_exam() << endl;
    outs << "Final Exam:   " << get_final_exam() << endl;
    outs << "Total score:  " << get_avg() << endl;
    outs << "Final Grade:  " << get_grade() << endl << endl;
}
//friend function definition that compares the students' scores
void compare(Student_record student_1, Student_record student_2)
{
    if (student_1.get_avg() > student_2.get_avg())
        cout << "Student_1 had better overall performance." << endl;
    else if (student_1.get_avg() == student_2.get_avg())
        cout << "The students performed equally." << endl;
    else
        cout << "Student_2 had better overall performance." << endl;
}
