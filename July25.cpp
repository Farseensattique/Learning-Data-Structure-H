#include<iostream>
using namespace std;

struct CallRecord
{
    long recentCall;
    string time;
    CallRecord *nextCall;
};

class CallHistory
{
public:
    CallRecord *firstCall = NULL;
    CallRecord *currentCall, *newCall;

    void latestCall(long recentCall , string time)
    {
        newCall = new CallRecord;
        newCall->recentCall = recentCall;
        newCall->time = time;
        newCall->nextCall = NULL;

        if(firstCall == NULL)
        {
            firstCall = newCall;
            currentCall = firstCall;
        }

        else
        {
            currentCall->nextCall = newCall;
            currentCall = newCall;
        }
    }

    void delete_OldestCall()
    {
        currentCall = firstCall;
        firstCall = currentCall->nextCall;
    }

    void displayCalls()
    {
        currentCall = firstCall;
        while(currentCall != NULL)
        {
            cout<<"Latest Call : "<<currentCall->recentCall<<"  attempted at "<<currentCall->time<<endl<<endl;
            currentCall = currentCall->nextCall;
        }
    }
};

int main()
{
    CallHistory c;

    c.latestCall(1711179612, "12:21 pm");
    c.latestCall(1311178114, "1:38 pm");
    c.latestCall(1322268914, "3:59 pm");
    c.delete_OldestCall();
    c.displayCalls();

    return 0;
}
