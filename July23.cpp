#include<iostream>
using namespace std;

struct StudentDetails
{
    string name;
    string id;
    float grade;
    StudentDetails *nextStudent;
};

class StudentRecord
{
public:
    StudentDetails *firstStudent = NULL;
    StudentDetails *currentStudent, *newStudent;

    void add_Student(string name, string id, float grade)
    {
        newStudent = new StudentDetails;
        newStudent->name = name;
        newStudent->id = id;
        newStudent->grade = grade;
        newStudent->nextStudent = NULL;

        if(firstStudent == NULL)
        {
            firstStudent = newStudent;
            currentStudent = firstStudent;
        }

        else
        {
            currentStudent->nextStudent = newStudent;
            currentStudent = newStudent;
        }
    }

    void add_FirstStudent(string name, string id, float grade)
    {
        newStudent = new StudentDetails;
        newStudent->name = name;
        newStudent->id = id;
        newStudent->grade = grade;
        newStudent->nextStudent = firstStudent;
        firstStudent = newStudent;
    }
    void showStudents()
    {
        currentStudent = firstStudent;
        while(currentStudent != NULL)
        {
            cout<<"Student Name : "<<currentStudent->name<<" (ID : "<<currentStudent->id<<") obtained CGPA "<<currentStudent->grade<<endl<<endl;
            currentStudent  = currentStudent->nextStudent;
        }
    }
};

int main()
{
    StudentRecord sr;
    sr.add_Student("Arif Hossain", "22-44813-2", 3.55);
    sr.add_Student("Shamima Shammi", "22-44773-3", 3.22);
    sr.add_Student("Julkar Junaid", "22-44722-2", 3.95);
    sr.add_FirstStudent("Jamia Sultana", "22-41833-2", 4.00);
    sr.add_FirstStudent("Kiran Punia", "21-33819-1", 3.65);

    sr.showStudents();

    return 0;
}
