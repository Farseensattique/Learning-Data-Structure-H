#include<iostream>
using namespace std;

const static int maxCapacity = 40;

class Fibonacci
{
public:
    int Stack[maxCapacity];
    int top=-1;

    void push(int next)
    {
        if(top < maxCapacity-1)
        {
            Stack[++top] = next;
            cout<<"Added Number in series : "<<next<<endl;
        }
        else
        {
          cout<<"Stack is full ! "<<endl;
        }
    }

    int pop()
    {
        if(top >= 0)
        {
            int removed = Stack[top--];
            cout<<"Removed the number from top : "<<removed<<endl;
            return removed;
        }
        else
        {
            cout<<"Stack is Empty ! "<<endl;
            return -1;
        }
    }

    int peek()
    {
        if(top >= 0)
        {
            cout<<"Number at the top right now : "<<Stack[top]<<endl;
            return Stack[top];
        }
        else
        {
            cout<<"Stack is Empty ! "<<endl;
        }
    }

    void implement(int n)
    {
        int first = 0;
        int second = 1;

        for (int i = 0; i < n; i++)
        {
            push(first);
            int next = first + second;
            first = second;
            second = next;
        }
    }
};

int main()
{
    Fibonacci series;
    int n;
    cout << "Enter total number of Fibonacci numbers to show: ";
    cin >> n;

    series.implement(n);
    series.peek();
    series.pop();
    series.peek();

    cout<<"The ultimate Fibonacci Series : ";
    for(int i=0; i<=series.top; i++)
    {
        cout<<series.Stack[i]<<" ";
    }

    return 0;
}
