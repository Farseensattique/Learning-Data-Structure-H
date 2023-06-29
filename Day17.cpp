#include<iostream>
using namespace std;

struct Cow
{
    int weight, price;
    string caste;
};

int main()
{
    int totalCows;
    cout<<"Enter total number of cows in the Farm : ";
    cin>>totalCows;

    Cow features[totalCows];

    cout<<"Enter the features of each Cow : "<<endl<<endl;
    for(int i=0; i<totalCows; i++)
    {
        cout<<"Weight : ";
        cin>>features[i].weight;
        cin.ignore();

        cout<<"Class : ";
        getline(cin, features[i].caste);

        cout<<"Price : ";
        cin>>features[i].price;

        cout<<endl;
    }

    int desire;
    cout<<"Enter your preferable amount for the cow : ";
    cin>>desire;

    int first = 0;
    int last = totalCows-1;
    int mid;
    while(first <= last)
    {
        mid = (first + last)/2;
        if(features[mid].price == desire)
        {
            cout<<"We have a cow at your desired price (BDT "<<features[mid].price<<")"<<endl;
            cout<<"Weight : "<<features[mid].weight<<" Kg "<<endl;
            cout<<"Class : "<<features[mid].caste<<endl;
            break;
        }

        else if(features[mid].price < desire)
        {
            first = mid+1;
        }
        else if(features[mid].price > desire)
        {
            last = mid-1;
        }
    }

    if(first > last)
    {
        cout<<"Sorry ! We don't have a cow at your desired amount (BDT "<<desire<<")"<<endl;
        cout<<"You can try for other deals"<<endl;
    }

    return 0;
}
