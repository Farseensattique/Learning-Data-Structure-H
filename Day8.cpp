#include <iostream>
using namespace std;

class Students
{
public:
    int totalStudents, totalSubjects;

    void result(int marks[][10], double average[])
    {
        for (int i = 0; i < totalStudents; i++)
        {
            double total = 0;
            for (int j = 0; j < totalSubjects; j++)
            {
                total += marks[i][j];
            }
            average[i] = total / totalSubjects;
        }
    }
};

int main()
{
    Students grade;
    cout << "Total number of Students: ";
    cin >> grade.totalStudents;
    cout << "Total Subjects: ";
    cin >> grade.totalSubjects;

    int marks[grade.totalStudents][10];
    double average[grade.totalStudents];

    for (int i = 0; i < grade.totalStudents; i++)
    {
        cout << "Enter marks for student " << i + 1 << ":" << endl;
        for (int j = 0; j < grade.totalSubjects; j++)
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    grade.result(marks, average);

    cout << "Average Grade for Each Student:" << endl;
    for (int i = 0; i < grade.totalStudents; i++)
    {
        cout << "Student " << i + 1 << ": " << average[i] << endl;
    }

    return 0;
}
