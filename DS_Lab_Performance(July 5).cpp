#include<iostream>
using namespace std;

const static int totalStudent = 4;

struct Students
{
    string name;
    double cgpa;
    string id;
};

int main()
{
    Students s[totalStudent];
    cout<<"Enter the name, id & cgpa of the students :"<<endl<<endl;
    for(int i=0; i<totalStudent; i++)
    {
        cout<<"Name : ";
        cin>>s[i].name;
        cout<<"ID : ";
        cin>>s[i].id;
        cout<<"CGPA : ";
        cin>>s[i].cgpa;
    }
    cout<<endl;

    int ran = 0;
    string us;
    cout<<"Select the options from below : "<<endl<<endl;
    string options[4] = {"1.Apply Insertion Sort", "2.Apply Bubble Sort", "3.Apply Selection Sort", "4.Apply Binary Search"};
    string perform[4] ={"1", "2", "3", "4"};
    for(int i=0 ;i< 4; i++)
    {
        cout<<options[i]<<endl;
    }
    cout<<endl;
    cout<<"Select the option that you want to perform : ";
    cin>>us;
    cout<<endl;

    for(int i=0; i<4; i++)
    {
        if(us == perform[i])
        {
            ran = i ;
        }
    }

    if(ran == 1)
    {
        for(int i=0; i<totalStudent-1; i++)
        {
            for(int j=0; j<totalStudent-1-i; j++)
            {
                if(s[j].cgpa > s[j+1].cgpa)
                {
                        Students temp = s[j];
                        s[j] = s[j+1];
                        s[j+1] = temp;
                }
            }
        }

        cout<<"CGPA sorted order through bubble sort ------->>>>>"<<endl<<endl;
        for(int i=0; i<totalStudent; i++)
        {
            cout<<s[i].name<<" whose ID is "<<s[i].id<<" obtained CGPA : "<<s[i].cgpa<<endl;
        }

    }

    if(ran == 2)
    {
        for(int i=0; i<totalStudent-1; i++)
        {
            for(int j=i+1; j<totalStudent; j++)
            {
                if(s[i].cgpa > s[j].cgpa)
                {
                    Students temp = s[j];
                    s[j]=s[i];
                    s[i] = temp;
                }
            }
        }

        cout<<"CGPA sorted through selection sort ------->>>>>"<<endl<<endl;

        for(int i=0; i<totalStudent; i++)
        {
            cout<<s[i].name<<" whose ID is "<<s[i].id<<" obtained CGPA : "<<s[i].cgpa<<endl;
        }
    }

    if(ran == 0)
    {
        for (int i = 1; i < totalStudent; i++)
        {
            Students temp = s[i];
            int ptr = i - 1;
            while (ptr >= 0 && s[ptr].cgpa > temp.cgpa)
            {
                s[ptr + 1] = s[ptr];
                ptr--;
            }
            s[ptr + 1] = temp;
        }

        cout<<"CGPA sorted through Insertion Sort ------->>>"<<endl;
        for(int i=0; i<totalStudent; i++)
        {
            cout<<s[i].name<<" whose ID is "<<s[i].id<<" obtained CGPA : "<<s[i].cgpa<<endl;
        }
    }

    if(ran == 3)
    {
        bool b= true;
        for(int i=0; i<totalStudent-1; i++)
        {
            for(int j=1; j<totalStudent; j++)
            {
                if(s[i].cgpa > s[j].cgpa)
                {
                    b = false;
                }
            }
        }
        if(!b)
        {
            int first = 0;
            int last = 3;
            int middle;
            double found;

            cout<<endl;

            cout<<"Enter the cgpa of any student : ";
            cin>>found;

            while(first < last)
            {
                middle=(first+last)/2;
                if(s[middle].cgpa == found)
                {
                    cout<<"The CGPA of "<<s[middle].name<<"(ID:  "<<s[middle].id<<") is "<<s[middle].cgpa<<endl;
                    break;
                }
                else if(s[middle].cgpa < found)
                {
                    first=middle+1;
                }
                else
                {
                    last=middle-1;
                }
            }

            if(first > last)
            {
                cout<<"The Student is not found"<<endl;
            }
        }
        else if(b)
        {
            cout<<"Binary search can't be applied since the all the cgpa are not sorted"<<endl;
        }

    }


    return 0;
}

