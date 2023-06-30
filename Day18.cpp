#include<iostream>
using namespace std;

const static int maxCalls = 5;
class PhoneCall
{
public:
    long Stack[maxCalls];
    int totalCalls = -1;

    void push(long insertion)
    {
        if(totalCalls < maxCalls-1)
        {
            Stack[++totalCalls] = insertion;
            cout<<"Added latest call : "<<insertion<<endl;
        }
        else
        {
            cout<<"Call History reached its limit ! "<<endl;
        }
    }

    long pop()
    {
        if(totalCalls>=0)
        {
            long deletion = Stack[totalCalls--];
            cout<<"Deleted phone call : "<<deletion<<endl;
            return deletion;
        }
        else
        {
            cout<<"Call History already deleted ! "<<endl;
            return -1;
        }
    }

    long latestCall()
    {
        if(totalCalls>=0)
        {
            cout<<"Latest Call at present : "<<Stack[totalCalls]<<endl;
            return Stack[totalCalls];
        }
        else
        {
            cout<<"No latest Call to show ! "<<endl;
            return -1;
        }
    }
};

int main()
{
    PhoneCall history;

    cout<<"Previous phone calls in the call history : "<<endl<<endl;

    history.push(1714025222);
    history.push(1714025111);
    history.pop();
    history.latestCall();
    history.pop();
    history.pop();

    return 0;
}

