#include <iostream>
using namespace std;

struct Course
{
    string name;
    Course *prev;
    Course *next;
};

class AvailableCourses
{
public:
    Course *first = NULL;
    Course *last = NULL;
    Course *newCourse, *current;

    void addCourse(string name)
    {
        newCourse = new Course;
        newCourse->name = name;
        newCourse->prev = last;
        newCourse->next = NULL;

        if (last != NULL)
        {
            last->next = newCourse;
        }
        else
        {
            first = newCourse;
        }
        last = newCourse;
    }

    void searchCourse(string name)
    {
        bool found = false;
        current = first;
        while (current != NULL)
        {
            if (current->name == name)
            {
                cout << current->name << " is available to select" << endl;
                found = true;
                return;
            }
            current = current->next;
        }
        if(!found)
        {
            cout<<name<<" is currently unavailable to select"<<endl;
        }
    }
};

int main()
{
    int totalCourses;
    cout << "Total number of available courses to register: ";
    cin >> totalCourses;
    cin.ignore();

    AvailableCourses c;
    string name;
    cout << "Enter the available courses for next Semester: " << endl<<endl;
    for (int i = 0; i < totalCourses; i++)
    {
        cout << "Course : ";
        getline(cin, name);
        cout << endl;
        c.addCourse(name);
    }

    string select;
    cout << "Search for any course: ";
    getline(cin, select);

    c.searchCourse(select);

    return 0;
}

