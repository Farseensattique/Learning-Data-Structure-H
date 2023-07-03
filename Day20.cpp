#include<iostream>
using namespace std;

class Pattern
{
public:
    int rows, columns;
};
int main()
{
    Pattern p;
    cout<<"Enter the number of rows : ";
    cin>>p.rows;

    p.columns = p.rows;
    int first = 1;
    int build[p.rows][p.columns];

    for(int i=0; i<p.rows; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout<<first<<" ";
            first++;
        }
        cout<<endl;
    }

    return 0;
}
