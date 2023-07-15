#include<iostream>
using namespace std;

const static int maxSize = 4;

class Difference
{
public:
    int arr[maxSize][maxSize];
    int sumD = 0 , sumB = 0;
    int countD = 0 , countB = 0;
};

int main()
{
    Difference d;

    cout<<"Enter the elements of the Array : "<<endl;
    for(int i=0; i<maxSize; i++)
    {
        for(int j=0; j< maxSize; j++)
        {
            cin>>d.arr[i][j];
        }
    }
    cout<<endl;

    for(int i=0; i<maxSize; i++)
    {
        for(int j=0; j<maxSize; j++)
        {
            if((i+j) == maxSize - 1 || i == j)
            {
                d.countD++;
                d.sumD += d.arr[i][j];
            }
        }
    }

    for(int i=0; i<maxSize; i++)
    {
        for(int j=0; j<maxSize; j++)
        {
            if(i==0 || j==0 || i==(maxSize-1) || j==(maxSize-1))
            {
                d.countB++;
                d.sumB += d.arr[i][j];
            }
        }
    }

    float avgD = (float)d.sumD / d.countD;
    float avgB = (float)d.sumB / d.countB;
    float diff;

    if(avgD > avgB)
    {
        diff = avgD - avgB;
    }

    else if(avgD <avgB)
    {
        diff = avgB-avgD;
    }

    else
    {
        diff = 0;
    }

    cout<<"Sum of the Diagonal elements : "<<d.sumD<<endl<<endl;
    cout<<"Sum of the Boundary elements : "<<d.sumB<<endl<<endl;
    cout<<"Average of the Diagonal elements : "<<avgD<<endl<<endl;
    cout<<"Average of the Boundary elements : "<<avgB<<endl<<endl;
    cout<<"The difference of the average of the boundary & diagonal elements of the 2D Array : "<<diff<<endl;

    return 0;
}
