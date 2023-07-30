#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *nextNode;
};

void CircularLinkedList(int n, Node *&firstNode)
{
    Node *currentNode = nullptr;

    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node();

        cout << "Enter data for Node " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->nextNode = nullptr;

        if (firstNode == nullptr)
        {
            firstNode = newNode;
            currentNode = newNode;
        }
        else
        {
            currentNode->nextNode = newNode;
            newNode->nextNode = firstNode;
            currentNode = newNode;
        }
    }
}

void display(Node *firstNode)
{
    if (firstNode == nullptr)
    {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node *currentNode = firstNode;
    cout << "Circular Linked List: ";
    do {
        cout << currentNode->data << " ";
        currentNode = currentNode->nextNode;
    } while (currentNode != firstNode);
    cout << endl;
}

int main()
{
    int n;
    Node *firstNode = nullptr;

    cout << "Enter the number of nodes: ";
    cin >> n;

    CircularLinkedList(n, firstNode);
    display(firstNode);

    return 0;
}
