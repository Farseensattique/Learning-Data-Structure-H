#include<iostream>
using namespace std;

struct Course
{
    int code;
    string name, faculty;
};

int main()
{
    int totalCourses;
    cout<<"Enter total number of courses : ";
    cin>>totalCourses;

    Course details[totalCourses];
    cout<<"Enter the details of individual courses : "<<endl;
    for(int i=0; i<totalCourses; i++)
    {
        cout<<"Course code : ";
        cin>>details[i].code;
        cin.ignore();

        cout<<"Course Name : ";
        getline(cin, details[i].name);

        cout<<"Course Faculty : ";
        getline(cin, details[i].faculty);

        cout<<"\n";
    }

    for (int i = 1; i < totalCourses; i++)
    {
        Course temp = details[i];
        int ptr = i - 1;
        while (ptr >= 0 && details[ptr].code < temp.code)
        {
            details[ptr + 1] = details[ptr];
            ptr--;
        }
        details[ptr + 1] = temp;
    }

    cout<<"Courses sorted in descending order through Insertion Sort ------->>>"<<endl;
    for(int i=0; i<totalCourses; i++)
    {
        cout<<"Code : "<<details[i].code<<endl;
        cout<<"Name : "<<details[i].name<<endl;
        cout<<"Faculty : "<<details[i].faculty<<endl;
        cout<<"\n\n";
    }

    return 0;
}
