#include<iostream>
using namespace std;

class Hotel
{
public:
    const static int maxGuest = 55;
    int totalGuests;
    string guest[maxGuest];
    int room[maxGuest];
    string checkIn[maxGuest];
    string wanted;

    void linearSearch()
    {
        bool stay=false;

        for(int i=0; i<totalGuests; i++)
        {
            if(guest[i] == wanted)
            {
                cout<<guest[i]<<" is staying in Room No "<<room[i]<<" and checked-in at "<<checkIn[i]<<" PM "<<endl;
                stay = true;
                break;
            }
        }
        if(!stay)
        {
             cout<<wanted<<" is not staying at our hotel"<<endl;
        }
    }
};

int main()
{
    Hotel bayView;

    cout<<"Enter the total number of guests staying today : ";
    cin>>bayView.totalGuests;
    cin.ignore();

    cout<<"Enter the details of individual guests : "<<endl;
    for(int i=0; i<bayView.totalGuests; i++)
    {
        cout<<"Guest Name : ";
        getline(cin, bayView.guest[i]);

        cout<<"Room Number : ";
        cin>>bayView.room[i];

        cout<<"Check-in time : ";
        cin>>bayView.checkIn[i];
        cin.ignore();

        cout<<"\n";
    }

    cout<<"Enter the guest name to search : ";
    getline(cin, bayView.wanted);

    bayView.linearSearch();

    return 0;
}
