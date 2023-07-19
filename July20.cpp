#include<iostream>
using namespace std;

struct Human
{
    string name;
    float weight;
    Human *nextHuman;
};

int main()
{
    Human *firstHuman, *currentHuman, *newHuman;

    newHuman = new Human;
    newHuman->name = "Arif Intisar";
    newHuman->weight = 75;
    firstHuman = newHuman;
    currentHuman = firstHuman;

    newHuman = new Human;
    newHuman->name = "Sadik Istiak";
    newHuman->weight = 80.5;
    currentHuman->nextHuman = newHuman;
    currentHuman = newHuman;

    newHuman = new Human;
    newHuman->name = "Ujjoyeni Dutta";
    newHuman->weight = 67.2;
    currentHuman->nextHuman = newHuman;
    currentHuman = newHuman;

    newHuman =  new Human;
    newHuman->name = "Shakib Hasan";
    newHuman->weight = 72.5;
    currentHuman->nextHuman = newHuman;
    currentHuman = newHuman;

    newHuman = new Human;
    newHuman->name = "Austin Oberoi";
    newHuman->weight = 60.8;
    newHuman->nextHuman = NULL;
    currentHuman->nextHuman = newHuman;

    string n;
    float least = 1000;

    currentHuman = firstHuman;
    while(currentHuman != NULL)
    {
        if(currentHuman->weight < least)
        {
            n = currentHuman->name;
            least = currentHuman->weight;
        }
        currentHuman = currentHuman->nextHuman;
    }

    cout<<n<<" possesses the least weight among all which is : "<<least<<" kg "<<endl;

    currentHuman = firstHuman;
    while(currentHuman != NULL)
    {
        Human *temp = currentHuman;
        currentHuman = currentHuman->nextHuman;
        delete temp;
    }

    return 0;
}
