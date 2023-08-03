#include<iostream>
using namespace std;

struct Passenger
{
    string bookingID;
    string name;
    string seatNumber;
    Passenger *next;
};

class FlightReservation
{
public:
    Passenger *first = NULL;
    Passenger *current, *newPassenger;

    void addReservation(string bookingID, string name, string seatNumber)
    {
        newPassenger = new Passenger;
        newPassenger->bookingID = bookingID;
        newPassenger->name = name;
        newPassenger->seatNumber = seatNumber;
        newPassenger->next = NULL;

        if(first == NULL)
        {
            first = newPassenger;
            current = first;
        }

        else
        {
            current->next = newPassenger;
            current = current->next;
        }
    }

    void deleteReservation(string bookingID)
    {
        if(first == NULL)
        {
            cout<<"No reservations done yet & so invaild deletion"<<endl<<endl;
            return;
        }

        if(first->bookingID == bookingID)
        {
            Passenger *temp = first;
            first = first->next;
            delete temp;
            return;
        }

        Passenger *prev = NULL;
        current = first;
        while(current != NULL)
        {
            if(current->bookingID == bookingID)
            {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Reservation with booking ID " << bookingID << " not found & so invalid deletion" << endl<<endl;
    }

    void displayReservations()
    {
        cout<<"Passenger Reservations -------->>>> "<<endl<<endl;
        current = first;
        while(current != NULL)
        {
            cout<<"Booking ID: "<<current->bookingID<<endl;
            cout<<"Passenger Name: "<<current->name<<endl;
            cout<<"Seat  Number: "<<current->seatNumber<<endl<<endl;
            current = current->next;
        }
    }
};

int main()
{
    FlightReservation f;
    f.deleteReservation("PR-171");
    f.addReservation("CR-221", "Tim David", "A3");
    f.addReservation("PR-351", "Johshua de Silva", "A2");
    f.addReservation("CX-212", "James Harvard", "B1");
    f.deleteReservation("PR-351");
    f.deleteReservation("CV-222");
    f.displayReservations();

    return 0;
}
