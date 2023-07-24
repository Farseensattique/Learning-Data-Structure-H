#include<iostream>
using namespace std;

struct BankTransaction
{
    string type;
    double amount;
    string date;
    BankTransaction *nextTransaction;
};

class TransactionHistory
{
public:
    BankTransaction *firstTransaction = NULL;
    BankTransaction *currentTransaction, *newTransaction;
    double sum = 0;

    void transaction_Done(string type, double amount, string date)
    {
        newTransaction = new BankTransaction;
        newTransaction->type = type;
        newTransaction->amount = amount;
        newTransaction->date = date;
        newTransaction->nextTransaction = NULL;

        if(firstTransaction == NULL)
        {
            firstTransaction = newTransaction;
            currentTransaction = firstTransaction;
        }

        else
        {
            currentTransaction->nextTransaction = newTransaction;
            currentTransaction = newTransaction;
        }
    }

    void calculation()
    {
        currentTransaction = firstTransaction;
        while(currentTransaction != NULL && sum >= 0)
        {
            if(currentTransaction->type == "Deposit")
            {
                sum += currentTransaction->amount;
            }

            else if(currentTransaction->type == "Withdrawal")
            {
                sum -=currentTransaction->amount;
            }
            currentTransaction = currentTransaction->nextTransaction;
        }
        cout<<"Account Balance : "<<sum<<endl<<endl;
    }

    void statement()
    {
        currentTransaction = firstTransaction;
        while(currentTransaction != NULL)
        {
            cout<<"Transaction Type : "<<currentTransaction->type<<endl;

            if(currentTransaction->type == "Deposit")
            {
                cout<<"Deposited Amount : "<<currentTransaction->amount<<endl;
            }

            else if(currentTransaction->type == "Withdrawal")
            {
                cout<<"Withdrawn Amount : "<<currentTransaction->amount<<endl;
            }

            cout<<"Date : "<<currentTransaction->date<<endl<<endl;

            currentTransaction = currentTransaction->nextTransaction;
        }
    }
};

int main()
{
    TransactionHistory t;

    t.transaction_Done("Deposit", 2000, "12/12/2021");
    t.transaction_Done("Deposit", 3500, "19/12/2021");
    t.transaction_Done("Withdrawal", 1000.5, "15/1/2022");
    t.transaction_Done("Deposit", 5500, "28/2/2022");
    t.transaction_Done("Withdrawal", 3000, "21/3/2022");
    t.statement();
    t.calculation();

    return 0;
}
