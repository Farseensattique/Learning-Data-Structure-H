#include<iostream>
using namespace std;

const static int maxCow = 20;

class CowWeight
{
public:
    float arr[maxCow];
    float smallest;
    float largest;
    float secondSmallest;
    float secondLargest;
};

int main()
{
    CowWeight cw;
    int cow;
    cout<<"Enter the number of the number of cows : ";
    cin>>cow;

    cout<<"Enter the weights of the cows : "<<endl;
    for(int i=0; i<cow; i++)
    {
        cin>>cw.arr[i];
    }

    cw.smallest = cw.arr[0];
    cw.largest = cw.arr[0];
    cw.secondSmallest = cw.arr[0];
    cw.secondLargest = cw.arr[0];

    for(int i=0; i<cow; i++)
    {
        if(cw.arr[i] < cw.smallest)
        {
            cw.secondSmallest = cw.smallest;
            cw.smallest = cw.arr[i];
        }
        else if(cw.arr[i] < cw.secondSmallest && cw.arr[i] != cw.smallest)
        {
            cw.secondSmallest = cw.arr[i];
        }
    }

    for(int i=0; i<cow; i++)
    {
        if(cw.arr[i] > cw.largest)
        {
            cw.secondLargest = cw.largest;
            cw.largest = cw.arr[i];
        }

        else if(cw.arr[i] > cw.secondLargest && cw.arr[i] != cw.largest)
        {
            cw.secondLargest = cw.arr[i];
        }
    }

    cout<<"Cow with the second highest weight : "<<cw.secondLargest<<" kg "<<endl<<endl;
    cout<<"Cow with the second lowest weight : "<<cw.secondSmallest<<" kg "<<endl<<endl;

    return 0;
}
