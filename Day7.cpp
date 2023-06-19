#include<iostream>
using namespace std;

class Movie
{
public:
    const static int totalMovie=4;
    const static int totalShows=2;
    string movieName[totalMovie];
    int showTime[totalMovie][totalShows];
};

int main()
{
    Movie ticket;

    for(int i=0;i<ticket.totalMovie;i++)
    {
        cout<<"Movie : ";
        cin>>ticket.movieName[i];
        cout<<"Shows at : "<<endl;
        for(int j=0;j<ticket.totalShows;j++)
        {
            cin>>ticket.showTime[i][j];
        }
    }

    for(int i=0;i<ticket.totalMovie;i++)
    {
        cout<<ticket.movieName[i]<<" will be aired at the following times : "<<endl;
        for(int j=0;j<ticket.totalShows;j++)
        {
            cout<<ticket.showTime[i][j]<<" PM "<<endl;
        }
    }

    return 0;
}
