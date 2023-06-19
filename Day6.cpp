#include<iostream>
using namespace std;
class Cricket
{
public:
    int overs, sum, target;
    float runRate;
    int *runs;
    void t10()
    {
        for(int i=0;i<overs;i++)
        {
            sum+=runs[i];
        }

        target=sum+1;
        runRate=(float)target/overs;
        cout<<"Total first innings score today : "<<sum<<endl;
        cout<<"The target for the opponent : "<<target<<endl;
        cout<<"Required run rate per over : "<<runRate<<endl;
    }
};

int main()
{
    Cricket match;
    match.overs = 10;
    match.sum = 0;
    match.runs = new int[match.overs];
    cout<<"Enter the runs scored per over : "<<endl;
    for(int i=0;i<match.overs;i++)
    {
        cin>>match.runs[i];
    }
    int highest=match.runs[0], highestOver=-1;
    for(int i=0;i<match.overs;i++)
    {
        if(match.runs[i]>highest)
        {
            highest=match.runs[i];
            highestOver=i+1;
        }
    }
    cout<<"Highest runs scored in over number "<<highestOver<<" which was "<<highest<<endl;
    match.t10();
    delete[] match.runs;

    return 0;
}
