/* *******************************************************

 * This header file provides a class declaration for the
 * Book class. It consists of constructors, getters, and 
 * setters to instantiate a Book with title, author, ISBN,
 * and publication year
 * 
 * *******************************************************/

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Library.h"
#include "Member.h"
using namespace std;

class Book {
    private:
        string title;
        string author;
        string ISBN;
        int pubYear;
    public:
        // Default constructor
        Book();

        // Fully parameterized constructor
        Book(string, string, string, int);

        // Getters
        string getTitle() const;
        string getAuthor() const;
        string getISBN() const;
        int getPubYear() const;

        // Setters
        void setTitle(string);
        void setAuthor(string);
        void setISBN(string);
        void setPubYear(int);
};

#endif