#include<iostream>
using namespace std;

struct Attendance
{
    char attendance;
    Attendance *prevClass;
    Attendance *nextClass;
};

class AttendanceList
{
public:
    Attendance *firstClass = NULL;
    Attendance *lastClass = NULL;
    Attendance *newClass, *currentClass;
    int mark = 10;

    void rollCall(char attendance)
    {
        newClass = new Attendance;
        newClass->attendance = attendance;
        newClass->prevClass = lastClass;
        newClass->nextClass = NULL;

        if(lastClass!= NULL)
        {
            lastClass->nextClass = newClass;
        }

        else
        {
            firstClass = newClass;
        }
        lastClass = newClass;
    }

    void attendanceMark()
    {
        currentClass = firstClass;
        while(currentClass != NULL)
        {
            if(currentClass->attendance == 'A')
            {
                mark--;
            }
            currentClass = currentClass->nextClass;
        }
        cout<<"Total Marks in Final Term for Attendance : "<<mark;
    }
};

int main()
{
    AttendanceList a;

    int totalClass = 10;
    char attendance;
    cout<<"Attendance throughout the semester : "<<endl<<endl;
    for(int i=0; i<totalClass; i++)
    {
        cout<<"Day "<<i+1<<" : ";
        cin>>attendance;
        a.rollCall(attendance);
    }

    a.attendanceMark();

    return 0;
}
