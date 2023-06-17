#include<iostream>
using namespace std;
class Restaurant
{
public:
    int totalOrders;
    string *order;
    int times=0;
    string item;
    void check()
    {
        for(int i=0;i<totalOrders;i++)
        {
            if(order[i]==item)
            {
                times++;
            }
        }
        cout<<item<<" was ordered "<<times<<" times during last hour";
    }
};

int main()
{
    Restaurant food;

    cout<<"Enter the total number of orders placed last hour : ";
    cin>>food.totalOrders;

    food.order = new string[food.totalOrders];
    cout<<"The foods sold in each order : "<<endl;
    for(int i=0;i<food.totalOrders;i++)
    {
        cin>>food.order[i];
    }

    cout<<"Enter the name of any food : ";
    cin>>food.item;

    food.check();
    delete[] food.order;
    return 0;

}
