#include<iostream>
using namespace std;

class MyChocolate
{
public:
    string chocolate[5];
    int top;
    int maxChocolates;

    MyChocolate(int totalChocolates)
    {
        maxChocolates = totalChocolates;
        top = 0;
    }

    bool isFull()
    {
        return(top == maxChocolates);
    }

    bool isVacant()
    {
        return(top == 0);
    }

    bool enter(string choco)
    {
        if(isFull())
        {
            cout<<"Jar is full of chocolates"<<endl;
            return false;
        }
        else
        {
            chocolate[top++] = choco;
            return true;
        }
    }

    bool pickedOff()
    {
        if(isVacant())
        {
            cout<<"All chocolates are eaten"<<endl;
            return false;
        }
        else
        {
            --top;
            return true;
        }
    }

    string topChocolate()
    {
        if(isVacant())
        {
            cout<<"The jar is Empty"<<endl;
            return "";
        }
        else
        {
            cout<<"Chocolate at the top of the jar : "<<chocolate[top-1]<<endl;
            return chocolate[top-1];
        }
    }

    void display()
    {
        if(isVacant())
        {
            cout<<"The jar is empty"<<endl;
        }
        else
        {
            cout<<"Chocolates in the jar at present : ";
            for(int i=0; i<top; i++)
            {
                cout<<chocolate[i]<<"\t";
            }
            cout<<endl;
        }
    }
};

int main()
{
    MyChocolate stack(5);

    stack.enter("Ferrero Rocher");
    stack.enter("Ritter Sport");
    stack.enter("Cadbury 5-Star");

    stack.display();

    stack.topChocolate();
    stack.pickedOff();

    stack.display();

    return 0;
}
