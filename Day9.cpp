#include <iostream>
#include <cstring>
using namespace std;

class User
{
public:
    const static int nameLength = 100;
    char first[nameLength];
    char last[nameLength];

};
int main() {
    User name;

    cout << "Enter the first name: ";
    cin.getline(name.first, name.nameLength);

    cout << "Enter the last name: ";
    cin.getline(name.last, name.nameLength);

    strcat(name.first, " ");
    strcat(name.first, name.last);

    cout << "Full Name of the User: ";
    for (int i = 0; name.first[i] != '\0'; i++)
    {
        cout << name.first[i];
    }
    cout << endl;

    int fullNameLength = strlen(name.first);
    cout << "Length of the Full Name: " << fullNameLength<< endl;

    return 0;
}
