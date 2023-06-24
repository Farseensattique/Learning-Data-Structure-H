#include<iostream>
using namespace std;

const static string months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

struct Officer
{
    char name[40];
    string designation;
    float salary[12];
    float increment;
    void monthlySalary()
    {
        for(int i=1;i<12;i++)
        {
            salary[i] = salary[i-1]+(salary[i-1]*increment);
        }
    }
};

int main()
{
    int totalOfficer;
    cout<<"Enter the total number of Officers : ";
    cin>>totalOfficer;

    Officer s[totalOfficer];

    for(int i=0; i<totalOfficer; i++)
    {
        cout<<"Name of the Officer : ";
        cin.ignore();
        cin.getline(s[i].name, 40);

        cout<<"Designation : ";
        cin>>s[i].designation;

        cout<<"Salary for the month of January : ";
        cin>>s[i].salary[0];

        cout<<"Monthly Increment rate for "<<s[i].name<<" : ";
        cin>>s[i].increment;

        s[i].monthlySalary();
    }

    cout<<"Month wise salary for each officer ------>>>"<<endl<<endl;
    for(int i=0; i<totalOfficer; i++)
    {
        cout<<"Salary of "<<s[i].designation<<" "<<s[i].name<<" : "<<endl<<endl;
        for(int j=0; j<12; j++)
        {
            cout<<months[j]<<" : "<<s[i].salary[j]<<endl;
        }
        cout<<"\n\n";
    }

    return 0;
}
