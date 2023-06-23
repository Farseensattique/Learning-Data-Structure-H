#include<iostream>
using namespace std;

struct FlightDetails
{
    string flightNumber;
    char destination[20];
    string date;
    int departure;

};

int main()
{
    FlightDetails fd[5];
    cout<<"Enter the Flight Numbers : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>fd[i].flightNumber;
    }

    cout<<"Enter the Destinatons : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>fd[i].destination;
    }

    cout<<"Enter the Dates : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>fd[i].date;
    }

    cout<<"Enter the Departure times : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>fd[i].departure;
    }

    cout<<"Details of Flights -------->>>>>"<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"Flight : "<<fd[i].flightNumber<<endl;
        cout<<"Destination : "<<fd[i].destination<<endl;
        cout<<"Date : "<<fd[i].date<<endl;
        cout<<"Departure : "<<fd[i].departure<<" o'clock "<<endl;
        cout<<"\n\n";
    }

    return 0;
}
