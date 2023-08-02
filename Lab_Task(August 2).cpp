#include <iostream>
using namespace std;

struct Transaction {
    string sender;
    string receiver;
    string date;
    double amount;
};

struct Node {
    Transaction data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node *head, *tail;
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insert(Transaction transaction) {
        Node* newNode = new Node;
        newNode->data = transaction;
        newNode->prev = NULL;
        newNode->next = head;

        if (head!=NULL)
            head->prev = newNode;
        else
            tail = newNode;

        head = newNode;
    }

    void printList() {
        Node* current = head;
        while (current!=NULL) {
            cout << "Sender: " << current->data.sender <<endl;
            cout << "Receiver: " << current->data.receiver <<endl;
            cout << "Date: " << current->data.date <<endl;
            cout << "Amount: " << current->data.amount <<endl;
            cout << "--------------------"<<endl<<endl;
            current = current->next;
        }
    }
};

class TransactionStack {
public:
    Node* top = NULL;

    void push(Transaction transaction) {
        Node* newNode = new Node;
        newNode->data = transaction;
        newNode->prev = NULL;
        newNode->next = top;

        if (top!=NULL)
            top->prev = newNode;

        top = newNode;
    }

    void pop() {
        if (top!=NULL) {
            Node* temp = top;
            top = top->next;
            if (top!=NULL)
                top->prev = NULL;
            delete temp;
        }
    }

    bool empty() {
        return top == NULL;
    }

    Transaction topTransaction() {
        return top->data;
    }
};

int main() {
    DoublyLinkedList transactionsList;
    TransactionStack transactionStack;
    int numTransactions;

    cout << "Enter the number of transactions: ";
    cin >> numTransactions;

    for (int i = 0; i < numTransactions; ++i) {
        Transaction transaction;
        cout << "Transaction " << i + 1 << ":\n";
        cout << "Sender: ";
        cin.ignore();
        getline(cin, transaction.sender);
        cout << "Receiver: ";
        getline(cin, transaction.receiver);
        cout << "Date: ";
        getline(cin, transaction.date);
        cout << "Amount: ";
        cin >> transaction.amount;

        transactionStack.push(transaction);
    }

    while (!transactionStack.empty()) {
        transactionsList.insert(transactionStack.topTransaction());
        transactionStack.pop();
    }

    cout<<endl<<"Transactions:"<<endl;
    transactionsList.printList();

    return 0;
}
