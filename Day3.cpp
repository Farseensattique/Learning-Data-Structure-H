#include<iostream>
using namespace std;
class Beverages
{
public:
    int totalVariety;
    int *price;
    int *quantity;
    int totalBill=0, vat=0.5, discount=0.10;
    void bill()
    {
        if(totalBill>500)
        {
            totalBill=totalBill+(totalBill*vat);
            if(totalBill>1000)
            {
                totalBill=totalBill-(totalBill*discount);
            }
        }
        cout<<"Total Bill for the customer : "<<totalBill;
    }

};
int main()
{
    Beverages b;
    b.price=new int[b.totalVariety];
    b.quantity=new int[100];
    string bname[b.totalVariety]={"Pepsi", "Fanta", "Coca-Cola", "Mountain Dew", "Mirinda", "Sprite"};
    cout<<"Enter the number of beverages in stock";
    cin>>b.totalVariety;
    cout<<"Enter the prices of the beverages";
    for(int i=0;i<b.totalVariety;i++)
    {
        cin>>b.price[i];
    }

    cout<<"Prices of individual beverages are listed below : "<<endl;
    for(int i=0;i<b.totalVariety;i++)
    {
        cout<<bname[i]<<" : "<<b.price[i]<<endl;
    }

    for(int i=0;i<b.totalVariety;i++)
    {
        cout<<bname[i]<<" : ";
        cin>>b.quantity[i];
    }
    for(int i=0;i<b.totalVariety;i++)
    {
        b.totalBill=b.price[i]*b.quantity[i];
    }
    b.bill();
    delete[] b.price;
    delete[] b.quantity;
    return 0;
}
