#include<iostream>
using namespace std;

const static int Maxsize = 4;

class QueueProperty
{
public:
    int Queue[Maxsize];
    int front = -1;
    int rear = -1;
};

class QueueImplementation : public QueueProperty
{
public:
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(rear == Maxsize - 1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Queue is Full ! Enqueue not possible since rear = "<<rear<<endl;
            cout<<"(front = "<<front<<" & rear = "<<rear<<")"<<endl<<endl;
        }

        else if(isEmpty())
        {
            front = rear = 0;
            Queue[rear] = x;
            cout<<"Enqueued element at "<<rear<<" index : "<<x<<endl;
            cout<<"(front = "<<front<<" & rear = "<<rear<<")"<<endl<<endl;
        }

        else
        {
            Queue[++rear] = x;
            cout<<"Enqueued element at "<<rear<<" index :"<<x<<endl;
            cout<<"(front = "<<front<<" & rear = "<<rear<<")"<<endl<<endl;
        }
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty ! Dequeue not possible since front = "<<front<<endl;
            cout<<"(front = "<<front<<" & rear = "<<rear<<")"<<endl<<endl;
        }

        else if(front == rear && front != -1)
        {
            cout << "Dequeued element from " << front << " index: " <<Queue[front]<<endl;
            front = rear= -1;
            cout<<"(front = "<<front<<" & rear = "<<rear<<")"<<endl<<endl;
        }

        else
        {
            cout<<"Dequeued element from "<<front<<" index : "<<Queue[front++]<<endl;
            cout<<"(front = "<<front<<" & rear = "<<rear<<")"<<endl<<endl;
        }
    }

    void frontElement()
    {
        if(isEmpty())
        {
            cout<<"There is no front element to show since front = "<<front<<endl<<endl;
        }

        else
        {
            cout<<"Front Element is "<<Queue[front]<<" at "<<front<<" index "<<endl<<endl;
        }
    }

    void showQueue()
    {
        if(isEmpty())
        {
            cout<<"No element exists in the Queue"<<endl<<endl;
        }
        else
        {
            cout<<"Queue Printed : "<<endl;
            for(int i = front; i <= rear; i++)
            {
                cout<<Queue[i]<<" ";
            }
            cout<<endl<<endl;
        }
    }
};

int main()
{
    QueueImplementation q;

    q.enqueue(5);
    q.dequeue();
    q.showQueue();
    q.dequeue();
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();
    q.frontElement();
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.frontElement();
    q.enqueue(11);
    q.dequeue();
    q.frontElement();
    q.showQueue();


    return 0;
}

