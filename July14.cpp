#include<iostream>
using namespace std;

const static int size = 10;

class Data
{
public:
    int arr[size];
};

int main()
{
    Data s;

    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>s.arr[i];
    }
    cout<<endl;

    for(int i=0; i< size-1; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(s.arr[j] > s.arr[j+1])
            {
                int temp = s.arr[j+1];
                s.arr[j+1] = s.arr[j];
                s.arr[j] = temp;
            }
        }
    }

    int newArr[size];
    int count = 0;

    cout<<"Even data sorted in Ascending order : ";
    for(int i=0; i<size; i++)
    {
        if(s.arr[i]%2 == 0)
        {
            newArr[count++] = s.arr[i];
            cout<<s.arr[i]<<" ";
        }
    }
    cout<<endl<<endl;

    cout<<"Odd data sorted in Descending order : ";
    for(int i=size-1; i>=0; i--)
    {
        if(s.arr[i]%2 != 0)
        {
            newArr[count++] = s.arr[i];
            cout<<s.arr[i]<<" ";
        }
    }
    cout<<endl<<endl;

    cout<<"Even Data sorted in ascending order & then odd data sorted in descending order : ";
    for(int i=0; i<size; i++)
    {
        cout<<newArr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
