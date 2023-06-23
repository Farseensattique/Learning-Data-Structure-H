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
    int totalFlights;
    cout<<"Enter the number of flights in operation : ";
    cin>>totalFlights;

    FlightDetails fd[totalFlights];

    cout<<"Enter the Flight Numbers : "<<endl;
    for(int i=0;i<totalFlights;i++)
    {
        cin>>fd[i].flightNumber;
    }

    cout<<"Enter the Destinations : "<<endl;
    for(int i=0;i<totalFlights;i++)
    {
        cin>>fd[i].destination;
    }

    cout<<"Enter the Dates : "<<endl;
    for(int i=0;i<totalFlights;i++)
    {
        cin>>fd[i].date;
    }

    cout<<"Enter the Departure times : "<<endl;
    for(int i=0;i<totalFlights;i++)
    {
        cin>>fd[i].departure;
    }

    cout<<"Details of Flights -------->>>>>"<<endl<<endl;
    for(int i=0;i<totalFlights;i++)
    {
        cout<<"Flight : "<<fd[i].flightNumber<<endl;
        cout<<"Destination : "<<fd[i].destination<<endl;
        cout<<"Date : "<<fd[i].date<<endl;
        cout<<"Departure : "<<fd[i].departure<<" o'clock "<<endl;
        cout<<"\n\n";
    }

    return 0;
}
