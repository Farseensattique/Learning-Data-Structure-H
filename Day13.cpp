#include<iostream>
using namespace std;

const static int times =6;

class Gold
{
public:
    double price[times];

    void bubbleSort()
    {
        for(int i=0; i<times-1; i++)
        {
            for(int j=0; j<times-i; j++)
            {
                if(price[j] < price[j+1])
                {
                    double temp = price[j];
                    price[j] = price[j+1];
                    price[j+1]=temp;
                }
            }
        }

        cout<<"Last 6 month Gold Prices in descending order : "<<endl;
        for(int i=0; i<times; i++)
        {
            cout<<"BDT "<<price[i]<<endl;
        }
    }
};

int main()
{
    Gold gram;
    cout<<"Enter prices of gold per gram in Bangladesh during last 6 months : "<<endl;
    for(int i=0; i<times; i++)
    {
        cin>>gram.price[i];
    }

    gram.bubbleSort();

    return 0;
}
