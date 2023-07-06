#include<iostream>
using namespace std;

const static int maxCalls = 6;

class CallLog
{
public:
    long latestCall;
};

class StackImplement : public CallLog
{
public:
    long Stack[maxCalls];
    int top = -1;

    void push(long latestCall)
    {
        if(top < maxCalls-1)
        {
            Stack[++top] = latestCall;
            cout<<"Added Latest Call : "<<latestCall<<endl<<endl;
        }
        else
        {
            cout<<"Call Log is full !"<<endl<<endl;
        }
    }

    int pop()
    {
        if(top >= 0)
        {
            long deletion = Stack[top--];
            cout<<"Deleted latest Call : "<<deletion<<endl<<endl;
            return deletion;
        }
        else
        {
            cout<<"No phone call to delete : "<<endl<<endl;
            return -1;
        }
    }

    int peek()
    {
        if(top >= 0)
        {
            cout<<"Latest call to show : "<<Stack[top]<<endl<<endl;
            return Stack[top];
        }
        else
        {
            cout<<"Call Log is empty !"<<endl<<endl;
            return -1;
        }
    }

    void display()
    {
        cout<<"All the phone calls in the Call Log : "<<endl;
        for(int i=0; i<maxCalls; i++)
        {
            cout<<Stack[i]<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    StackImplement number;
    number.push(1711174242);
    number.push(1711174141);
    number.push(1711174020);
    number.pop();
    number.pop();
    number.peek();
    number.push(1711161111);
    number.peek();
    number.pop();
    number.pop();
    number.pop();
    number.peek();

    return 0;
}

