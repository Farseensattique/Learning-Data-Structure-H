#include<iostream>
using namespace std;

class Beverages
{
public:
    int totalVariety=6;
    int *price;
    int *quantity;
    int totalBill=0;
    float vat=0.05; 
    float discount=0.1;

    void bill()
    {
        if(totalBill>500)
        {
            totalBill+=totalBill*vat;
            if(totalBill>1000)
            {
                totalBill-=totalBill*discount;
            }
        }
        cout<<"Total Bill for the customer : "<<totalBill<< " BDT " << endl;
    }
};

int main()
{
    Beverages b;
    
    b.price=new int[b.totalVariety];
    b.quantity=new int[b.totalVariety];
    string bname[b.totalVariety]={"Pepsi", "Fanta", "Coca-Cola", "Mountain Dew", "Mirinda", "Sprite"};

    cout<<"Enter the prices of the individual beverages : << endl";
    for(int i=0;i<b.totalVariety;i++)
    {
        cout<<"bname[i]<<" : ";
        cin>>b.price[i];
    }

    cout<<"Enter the quantities of sold beverages of each brand : "<<endl;
    for(int i=0;i<b.totalVariety;i++)
    {
        cout<<bname[i]<<" : ";
        cin>>b.quantity[i];
    }

    for(int i=0;i<b.totalVariety;i++)
    {
        b.totalBill+=b.price[i]*b.quantity[i];
    }
    
    b.bill();
    
    delete[] b.price;
    delete[] b.quantity;
    
    return 0;
}
