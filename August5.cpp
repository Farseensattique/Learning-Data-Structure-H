#include<iostream>
using namespace std;

struct CalenderEvent
{
    string event;
    int date;
    CalenderEvent *next;
};

class EventManangement
{
public:
    CalenderEvent *first = NULL;
    CalenderEvent *current, *newEvent;

    CalenderEvent *createEvent(string event, int date)
    {
        newEvent = new CalenderEvent;
        newEvent->event = event;
        newEvent->date = date;
        newEvent->next = NULL;
        return newEvent;
    }

    CalenderEvent *insertEvent(CalenderEvent *first, string event, int date)
    {
        newEvent = createEvent(event , date);

        if(!first || date < first->date)
        {
            newEvent->next = first;
            first = newEvent;
            return first;
        }

        current = first;
        while(current->next && current->next->date < date)
        {
            current = current->next;
        }

        newEvent->next = current->next;
        current->next = newEvent;
        return first;
    }

    void displayEvents(CalenderEvent *first)
    {
        CalenderEvent *temp = first;
        while(temp != NULL)
        {
            cout<<temp->event<<" scheduled on "<<temp->date<<endl;
            temp = temp->next;
        }
    }
};

int main()
{
    EventManangement e;

    CalenderEvent *calender = NULL;

    calender = e.insertEvent(calender, "Math Quiz" , 12);
    calender = e.insertEvent(calender, "Physics Quiz", 11);
    calender = e.insertEvent(calender, "DM Quiz", 13);
    calender = e.insertEvent(calender, "DS Quiz", 14);

    cout<<"Calender Events ------->>>>"<<endl<<endl;
    e.displayEvents(calender);

    return 0;
}
