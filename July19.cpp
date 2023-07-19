#include<iostream>
using namespace std;

struct LostFound
{
    string foundItem;
    LostFound *nextFound;
};

int main()
{
    LostFound *firstItem, *currentItem, *newFound;

    newFound = new LostFound;
    newFound->foundItem = "Money Bag";
    firstItem = newFound;
    currentItem = firstItem;

    newFound = new LostFound;
    newFound->foundItem = "Watch";
    currentItem->nextFound = newFound;
    currentItem = newFound;

    newFound = new LostFound;
    newFound->foundItem = "Calculator";
    currentItem->nextFound = newFound;
    currentItem = newFound;

    newFound = new LostFound;
    newFound->foundItem = "Purse";
    currentItem->nextFound = newFound;
    currentItem = newFound;

    newFound = new LostFound;
    newFound->foundItem = "Mobile";
    newFound->nextFound = NULL;
    currentItem->nextFound = newFound;

    string item;
    bool found = false;
    cout<<"Enter the item to be searched : ";
    getline(cin, item);
    cout<<endl;

    currentItem = firstItem;
    while(currentItem != NULL)
    {
        if(currentItem->foundItem == item)
        {
            found = true;
            break;
        }
        currentItem = currentItem->nextFound;
    }

    if(!found)
    {
        cout<<item<<" is not found "<<endl;
    }
    else
    {
        cout<<item<<" is found"<<endl;
    }

    currentItem = firstItem;
    while(currentItem != NULL)
    {
        LostFound *temp = currentItem;
        currentItem = currentItem->nextFound;
        delete temp;
    }

    return 0;
}
