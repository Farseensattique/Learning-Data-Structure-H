#include<iostream>
using namespace std;
int main()
{
    int totalStationary=5;
    string stationary[totalStationary]={"Pen", "Pencil", "Sharpener", "NoteBook", "Scale"};
    int price[totalStationary];
    cout<<"Enter the prices of the stationeries sequentially: "<<endl;
    for(int i=0;i<totalStationary;i++)
    {
        cin>>price[i];
    }
    cout<<"The prices of individual stationeries : "<<endl;
    for(int i=0;i<totalStationary;i++)
    {
        cout<<stationary[i]<<" : "<<price[i]<<" BDT"<<endl;
    }
    int random=0;
    int maxprice=price[0];
    for(int i=0;i<totalStationary;i++)
    {
        if(price[i]>maxprice)
        {
            maxprice=price[i];
            random=i;
        }
    }
    cout<<"The maximum priced stationary is "<<stationary[random]<<" which will cost "<<price[random]<<" BDT"<<endl;
    return 0;
}
