#include<iostream>
using namespace std;

const static int kitchenCapacity = 5;

class RestaurantOrder
{
public:
    string orderQueue[kitchenCapacity];
    int frontOrder = -1, newestOrder = -1;

    bool noCapacity()
    {
        if((newestOrder+1)%kitchenCapacity == frontOrder)
        {
            return true;
        }
        return false;
    }

    bool fullCapacity()
    {
        if(frontOrder == -1 && newestOrder ==-1)
        {
            return true;
        }
        return false;
    }

    void placedOrder(string order)
    {
        if(noCapacity())
        {
            cout<<"New order can't be accepted"<<endl<<endl;
        }

        else if(fullCapacity())
        {
            frontOrder =  newestOrder = 0;
            orderQueue[newestOrder] = order;
            cout<<"New order accepted : "<<orderQueue[newestOrder]<<endl<<endl;
        }

        else
        {
            newestOrder = (newestOrder+1)%kitchenCapacity;
            orderQueue[newestOrder] = order;
            cout<<"New order accepted : "<<orderQueue[newestOrder]<<endl<<endl;
        }
    }

    void completedOrder()
    {
        if(fullCapacity())
        {
            cout<<"No order placed to complete"<<endl<<endl;
        }

        else if(frontOrder == newestOrder && frontOrder != -1)
        {
            cout<<"Order Completed : "<<orderQueue[frontOrder]<<endl<<endl;
            frontOrder =  newestOrder = -1;
        }

        else
        {
            cout<<"Order Completed : "<<orderQueue[frontOrder]<<endl<<endl;
            frontOrder = (frontOrder+1)%kitchenCapacity;
        }
    }

    void firstPriority()
    {
        cout<<"Prioritized Order : "<<orderQueue[frontOrder]<<endl<<endl;
    }
};

int main()
{
    RestaurantOrder o;

    o.placedOrder("Chicken Cordon-bleu");
    o.placedOrder("Mango Smoothie");
    o.placedOrder("Chicken Pinwheel");
    o.placedOrder("Lamb Shank");
    o.placedOrder("Prawn Gyoza");
    o.placedOrder("Mutton Roganjosh");
    o.completedOrder();
    o.firstPriority();

    return 0;
}
