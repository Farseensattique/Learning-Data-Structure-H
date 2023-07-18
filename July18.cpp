#include<iostream>
using namespace std;

const static int size = 8;

class Cipher
{
public:
    char password[size];
};

int main()
{
    Cipher c;

    cout<<"Input the password letters : "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>c.password[i];
    }

    for(int i=0; i<size; i++)
    {
        if(c.password[i]>='a' && c.password[i]<='z')
        {
            c.password[i] -= 32;
        }

        else if(c.password[i]>='A' && c.password[i]<='Z')
        {
            c.password[i] += 32;
        }
    }

    cout<<"Encrypted Password : ";
    for(int i=0; i<size; i++)
    {
        cout<<c.password[i];
    }

    return 0;
}
