#include<iostream>
using namespace std;

struct Book
{
    string book;
    string author;
    Book *nextBook;
};

class Library
{
public:
    Book *firstBook = NULL , *currentBook, *newBook;

    void addBook(string book, string author)
    {
        newBook = new Book;
        newBook->book = book;
        newBook->author = author;
        newBook->nextBook = NULL;

        if(firstBook == NULL)
        {
            firstBook = newBook;
            currentBook = firstBook;
        }

        else
        {
            currentBook->nextBook = newBook;
            currentBook = newBook;
        }
    }

    void display()
    {
        currentBook = firstBook;
        while(currentBook != NULL)
        {
            cout << "Book Name: " << currentBook->book << ", Author: " << currentBook->author << endl << endl;
            currentBook = currentBook->nextBook;
        }
    }

    void BookSearch(string need)
    {
        bool found = false;
        currentBook = firstBook;
        while(currentBook != NULL)
        {
            if(currentBook->book == need || currentBook->author == need)
            {
                found = true;
                break;
            }
            currentBook = currentBook->nextBook;
        }

        if(!found)
        {
            cout<<"This book is unavailable"<<endl;
        }

        else
        {
            cout<<"The Book is found"<<endl;
            cout<<"Book : "<<currentBook->book<<" , Author : "<<currentBook->author<<endl;
        }
    }
};

int main()
{
    Library b;
    b.addBook("Lily", "Thomas Edinburg");
    b.addBook("Night Sky", "James Briat");
    b.addBook("Alpha", "Nikhil Malik");
    b.display();

    string need;
    cout<<endl;
    cout<<"Enter the Book name / Author name of the book : ";
    getline(cin, need);
    b.BookSearch(need);

    return 0;
}
