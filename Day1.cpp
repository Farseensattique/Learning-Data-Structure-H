#include<iostream>
using namespace std;
class temp
{
public:
    int totalReadings;
    float sum=0;
    float *readings;
    void average()
    {
        for(int i=0;i<totalReadings;i++)
        {
            sum+=readings[i];
        }
        cout<<"Average of today's temperature readings  : "<<sum/totalReadings<<endl;
    }
};
int main()
{
    temp o;
    cout<<"Total number of readings to enter today : ";
    cin>>o.totalReadings;
    o.readings=new float[o.totalReadings];
    cout<<"Enter the temperature readings throughout the day : "<<endl;
    for(int i=0;i<o.totalReadings;i++)
    {
        cin>>o.readings[i];
    }
    o.average();
    delete[] o.readings;
    return 0;
}
