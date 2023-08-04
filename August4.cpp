#include<iostream>
using namespace std;

struct FriendRequest
{
    string senderName;
    FriendRequest *next;
};

class FriendRequestSystem
{
public:
    FriendRequest *first = NULL;
    FriendRequest *newRequest, *currentRequest;

    void sendFriendRequest(string senderName)
    {
        newRequest = new FriendRequest;
        newRequest->senderName = senderName;
        newRequest->next = NULL;

        if(first == NULL)
        {
            first = newRequest;
            currentRequest = first;
        }

        else
        {
            currentRequest->next = newRequest;
            currentRequest = currentRequest->next;
        }
    }

    void acceptFriendRequest(string senderName)
    {
        if(first->senderName == senderName)
        {
            FriendRequest *temp = first;
            first = first->next;
            delete temp;
            return;
        }

        FriendRequest *prev = NULL;
        currentRequest = first;
        while(currentRequest != NULL)
        {
            if(currentRequest->senderName == senderName)
            {
                prev->next = currentRequest->next;
                delete currentRequest;
                return;
            }
            prev = currentRequest;
            currentRequest = currentRequest->next;
        }
    }

    void displayPendingRequests()
    {
        cout<<"Pending Friend Requests -------->>>>"<<endl;
        currentRequest = first;
        while(currentRequest != NULL)
        {
            cout<<currentRequest->senderName<<endl;
            currentRequest = currentRequest->next;
        }
    }
};

int main()
{
    FriendRequestSystem fr;
    fr.sendFriendRequest("Joe Denly");
    fr.sendFriendRequest("Arvind Srivasth");
    fr.sendFriendRequest("Erin Smith");
    fr.sendFriendRequest("Jakir Mahmud");

    fr.acceptFriendRequest("Erin Smith");
    fr.acceptFriendRequest("Joe Denly");

    fr.displayPendingRequests();

    return 0;
}
