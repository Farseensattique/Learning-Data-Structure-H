#include<iostream>
using namespace std;

struct Contact
{
    long num;
    string user;
    Contact *left , *right;

    Contact(long number , string name)
    {
        num = number;
        user = name;
        left = NULL;
        right = NULL;
    }
};

class ContactBST
{
public:
    Contact *addContact(Contact *root, Contact *newContact)
    {
        if(root == NULL)
        {
            root =  newContact;
        }

        else
        {
            Contact *current = root;
            while(current != NULL)
            {
                if(newContact->user < current->user)
                {
                    if(current->left != NULL)
                    {
                        current = current->left;
                    }

                    else
                    {
                        current->left = newContact;
                        break;
                    }
                }

                else if(newContact->user > current->user)
                {
                    if(current->right != NULL)
                    {
                        current = current->right;
                    }

                    else
                    {
                        current->right = newContact;
                        break;
                    }
                }

                else
                {
                    break;
                }
            }
        }
        return root;
    }

    void inOrderTraversal(Contact *root)
    {
        if(root != NULL)
        {
            inOrderTraversal(root->left);
            cout<<root->num<<" is the contact number of "<<root->user<<endl<<endl;
            inOrderTraversal(root->right);
        }
    }
};

int main()
{
    int total;
    cout<<"Enter the total number of Contacts : ";
    cin>>total;
    cout<<endl;

    ContactBST c;
    Contact *root = NULL;

    for(int i=0; i<total; i++)
    {
        long num;
        string user;

        cin.ignore();
        cout<<"User Name : ";
        getline(cin , user);

        cout<<"Contact Number : ";
        cin>>num;
        cout<<endl;

        Contact *newContact =new Contact(num , user);
        root = c.addContact(root , newContact);
    }

    cout<<"User Contacts are listed in ascending order according to user name ------>>>"<<endl<<endl;
    c.inOrderTraversal(root);

    return 0;
}
