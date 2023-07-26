#include<iostream>
using namespace std;

const static int maxSize = 4;

class QueueImplementation
{
public:
    int queue[maxSize];
    int front = -1 , rear = -1;

    bool isFull()
    {
        if(rear == maxSize - 1)
        {
            return  true;
        }
        return false;
    }

    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Element can't be enqueued anymore since Queue is Full"<<endl<<endl;
        }

        else if(isEmpty())
        {
            front = rear = 0;
            queue[rear] = x;
            cout<<"Enqueued element : "<<queue[rear]<<endl<<endl;
        }

        else
        {
            queue[++rear] = x;
            cout<<"Enqueued element : "<<queue[rear]<<endl<<endl;
        }
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"No element in the queue exists to dequeue"<<endl<<endl;
        }

        else if(front == rear && front != -1)
        {
            cout<<"Dequeued Element : "<<queue[front]<<endl<<endl;
            front = rear = -1;
        }

        else
        {
            cout<<"Dequeued Element : "<<queue[front++]<<endl<<endl;
        }
    }

    void frontElement()
    {
        if(isEmpty())
        {
            cout<<"No front element to show "<<endl<<endl;
        }

        else
        {
            cout<<"Element at the front position : "<<queue[front]<<endl<<endl;
        }
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"No element exists in the Queue to display"<<endl<<endl;
        }

        else
        {
            cout<<"Queue displayed : ";
            for(int i=front; i<=rear; i++)
            {
                cout<<queue[i]<<" ";
            }
            cout<<endl<<endl;
        }
    }
};

int main()
{
    QueueImplementation q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.frontElement();
    q.display();

    return 0;
}
