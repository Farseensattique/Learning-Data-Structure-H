#include<iostream>
using namespace std;
class Pastry
{
public:
    const static int types=8;
    string varieties[types]={"Tiramisu", "Mango", "Cheese", "Vanilla", "Chocolate", "Strawberry", "Black Forest", "Lemon"};
    string choose;
    int wish=-1;
    char fresh;
    void menu()
    {
        for(int i=0;i<types;i++)
        {
            if(varieties[i]==choose)
            {
                wish++;
                cout<<"Sure! We are ready to serve you "<<varieties[i]<<" cake";
                break;
            }
        }
        if(wish<0)
        {
            cout<<"Sorry! Your selected pastry is not included in our menu"<<endl;
            cout<<"Do you want to add "<<choose<<" cake to your Wishlist ? (Y/N)"<<endl;
            cin>>fresh;
            if(fresh=='Y')
            {
                cout<<choose<<" cake is added to your Wishlist"<<endl;
            }
            else if(fresh=='N')
            {
                cout<<"We hope to serve you in near future"<<endl;
            }
        }
    }
};

int main()
{
    Pastry cake;

    cout<<"Which Pastry do you want?"<<endl;
    cin>>cake.choose;
    cake.menu();
    return 0;
}
