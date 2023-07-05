#include<iostream>
using namespace std;

struct OnlineStore
{
    string products;
    int code;
};

int main()
{
    int variety;
    cout<<"Enter total varieties of products in the Online Store : ";
    cin>>variety;
    cin.ignore();

    OnlineStore pro[variety];

    cout<<"Enter varieties of products in the store : "<<endl<<endl;
    for(int i=0; i<variety; i++)
    {
        cout<<"Product Type : ";
        getline(cin, pro[i].products);

        cout<<"Product Code : ";
        cin>>pro[i].code;
        cin.ignore();

        cout<<endl;
    }

    int found;
    cout<<"Enter the code of a particular product : ";
    cin>>found;
    cout<<endl;

    int first = 0;
    int last = variety-1;
    int mid;
    while(first <= last)
    {
        mid = (first + last)/2;
        if(pro[mid].code == found)
        {
            cout<<pro[mid].products<<" found in stock "<<endl;
            break;
        }

        else if(pro[mid].code < found)
        {
            first = mid+1;
        }
        else if(pro[mid].code > found)
        {
            last = mid-1;
        }
    }

    if(first > last)
    {
        cout<<"No product found in stock according to the entered code "<<endl;
    }

    return 0;
}

