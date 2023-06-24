#include<iostream>
using namespace std;

struct FoodOrder
{
    string orderId;
    string customerName;
    string foodName;
    float bill;
    string orderStatus;
};

int main()
{
    int totalOrder;
    cout<<"Enter total number of orders placed : ";
    cin>>totalOrder;

    FoodOrder fo[totalOrder], *fp;
    fp=fo;

    for(int i=0;i<totalOrder;i++)
    {
        cout<<"Order ID : ";
        cin>>fp->orderId;
        cin.ignore();

        cout<<"Ordered by : ";
        getline(cin, fp->customerName);

        cout<<"Food ordered : ";
        getline(cin, fp->foodName);

        cout<<"Total Bill : ";
        cin>>fp->bill;
        cin.ignore();

        cout<<"Order Current Status : ";
        getline(cin, fp->orderStatus);

        cout<<"\n";

        fp++;
    }

    for(int i=0;i<totalOrder;i++)
    {
        cout<<"Order "<<i+1<<" Details ------>>>> "<<endl;
        cout<<"Order ID :"<<fo[i].orderId<<endl;
        cout<<"Ordered by : "<<fo[i].customerName<<endl;
        cout<<"Food ordered : "<<fo[i].foodName<<endl;
        cout<<"Total Bill : "<<fo[i].bill<<endl;
        cout<<"Order Current Status : "<<fo[i].orderStatus<<endl;
        cout<<"\n\n";
    }

    return 0;
}
