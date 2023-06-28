#include<iostream>
using namespace std;

struct Football
{
    string player, team;
    int goals;
};

int main()
{
    int players;
    cout<<"Enter the number of players who scored goals in FIFA World cup-2022 : ";
    cin>>players;
    cin.ignore();

    Football match[players];

    for(int i=0; i<players; i++)
    {
        cout<<"Player Name : ";
        getline(cin, match[i].player);

        cout<<"Team : ";
        getline(cin, match[i].team);

        cout<<"Goal Scored : ";
        cin>>match[i].goals;

        cout<<"\n";
        cin.ignore();
    }

    for(int i=0; i<players-1; i++)
    {
        for(int j=i+1; j<players; j++)
        {
            if(match[i].goals < match[j].goals)
            {
                Football temp = match[j];
                match[j]=match[i];
                match[i] = temp;
            }
        }
    }

    cout<<"Highest goal scoring players in the world cup : "<<endl<<endl;
    for(int i=0; i<players; i++)
    {
        cout<<match[i].goals<<" goals were scored by "<<match[i].player<<" for "<<match[i].team<<endl<<endl;
    }

    return 0;
}
