#include<iostream>
using namespace std;

struct Employee
{
    string name;
    int salary;
    Employee *next, *prev;
};

class EmployeeDetails
{
public:
    Employee *first = NULL, *last = NULL;
    Employee *current, *newEmployee;

    void employee(string name, int salary)
    {
        newEmployee = new Employee;
        newEmployee->name = name;
        newEmployee->salary = salary;
        newEmployee->prev = last;
        newEmployee->next = NULL;

        if(last != NULL)
        {
            last->next = newEmployee;
        }

        else
        {
            first = newEmployee;
        }
        last = newEmployee;
    }

    void show()
    {
        current = last;
        while(current != NULL)
        {
            cout<<current->name<<" receives "<<current->salary<<" as Monthly Salary"<<endl<<endl;
            current = current->prev;
        }
    }
};

int main()
{
    int total;
    cout<<"Enter the number of employees : ";
    cin>>total;


    EmployeeDetails e;

    for(int i=0; i<total; i++)
    {
        string name;
        int salary;
        cout<<"Enter the name of the Employee : ";
        cin>>name;
        cout<<"Enter the salary of the Employee : ";
        cin>>salary;
        e.employee(name, salary);
        cout<<endl;
    }

    e.show();

    return 0;
}
