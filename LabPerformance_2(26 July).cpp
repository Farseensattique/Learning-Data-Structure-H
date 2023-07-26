#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *nextNode;
};

class LinkedList
{
public:
    Node *firstNode = NULL;
    Node *newNode , *currentNode;
    int maxElement = 0;

    void addElement(int data)
    {
        newNode = new Node;
        newNode->data = data;
        newNode->nextNode = NULL;

        if(firstNode == NULL)
        {
            firstNode = newNode;
            currentNode = firstNode;
        }

        else
        {
            currentNode->nextNode = newNode;
            currentNode = newNode;
        }
        maxElement++;
    }

    void bubbleSort()
    {
        for(int i=0; i<maxElement - 1; i++)
        {
            currentNode = firstNode;
            for(int j=0; j<maxElement-1-i ; j++)
            {
                if(currentNode->data > currentNode->nextNode->data)
                {
                    int temp = currentNode->data;
                    currentNode->data = currentNode->nextNode->data;
                    currentNode->nextNode->data = temp;
                }
                currentNode = currentNode->nextNode;
            }
        }
    }


    void showElement()
    {
        cout<<"Linked List Printed : ";
        currentNode = firstNode;
        while(currentNode != NULL)
        {
            cout<<currentNode->data<<" ";
            currentNode = currentNode->nextNode;
        }
        cout<<endl<<endl;
    }
};

int main()
{
    LinkedList l;

    l.addElement(10);
    l.addElement(5);
    l.addElement(25);
    l.addElement(15);
    l.showElement();
    l.bubbleSort();
    l.showElement();

    return 0;
}
