/* *******************************************************

 * This header file provides a class declaration for the
 * Member class. It consists of constructors, getters, setters,
 * functions to borrow and return books, view late fees, and view
 * section access. This is a base class for the derived 
 * classes Adult and Child.
 * 
 * *******************************************************/

#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"
using namespace std;

class Book;
class Library;

class Member {
    protected:
        string name;
        int age;
        int cardNumber;
        int lateFees = 0;
        vector<Book*> booksBorrowed;
    public:
        // Default constructor
        Member();

        // Full parameterized constructor
        Member(string, int, int);

        // Getters
        string getName() const;
        int getAge() const;
        int getCardNumber() const;
        int getLateFees() const;

        // Setters
        void setName(string);
        void setAge(int);
        void setCardNumber(int);

        // Functions
        void borrowBook(string, Library&);
        // desc: adds Book from Library catalog to booksBorrowed vector based on title
        // receives: title as string
        // returns: nothing

        void returnBook(string);
        // desc: deletes a pointer of Book from booksBorrowed based on string title
        // receives: title as string
        // returns: nothing

        void viewBorrowed();
        // desc: shows all Books borrowed from vector booksBorrowed
        // receives: nothing
        // returns: nothing

        // Pure virtual function - makes this class Abstract
        virtual void sectionAccess() = 0;
        // desc: pure virtual function for derived classes, determines member's access to sections
        // receives: nothing
        // returns: nothing
};

#endif