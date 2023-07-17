#include<iostream>
using namespace std;

const static int totalNotes = 10;

class BankNotes
{
public:
    int notes[totalNotes];
};

int main()
{
    BankNotes n;
    int sum = 0;
    int amount;
    int sumNotes = 0;
    int count = 0;

    cout<<"Enter the bank note values : "<<endl;
    for(int i=0; i<totalNotes; i++)
    {
        cin>>n.notes[i];
    }

    for(int i=0; i<totalNotes-1; i++)
    {
        for(int j=i+1; j<totalNotes; j++)
        {
            if(n.notes[j] > n.notes[i])
            {
                int temp = n.notes[j];
                n.notes[j] = n.notes[i];
                n.notes[i] = temp;
            }
        }
    }

    cout<<"Bank notes sorted in Descending order using Selection Sort : ";
    for(int i=0; i<totalNotes; i++)
    {
        cout<<n.notes[i]<<" ";
        sum += n.notes[i];
    }
    cout<<endl<<endl;

    cout<<"Total Amount of taka : "<<sum<<endl<<endl;

    cout<<"Provide an amount less than total amount : ";
    cin>>amount;
    cout<<endl;

    for(int i=0; i<totalNotes; i++)
    {
        count++;
        sumNotes += n.notes[i];
        if(sumNotes >= amount)
        {
            break;
        }
    }

    cout<<"Total "<<count<<" notes needed to equalize the amount "<<amount<<" which are : ";
    for(int i=0; i< count; i++)
    {
        cout<<n.notes[i]<<" ";
    }
    cout<<endl;

    return 0;
}
