/* *******************************************************

 * This header file provides a class declaration for the
 * Library class. It consists of a constructor/destructor and
 * functions to add, edit, and remove not only books in the library
 * but the member list as well. This implements file manipulation,
 * STL containers, etc.
 * 
 * *******************************************************/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
using namespace std;

class Book;
class Member;
class Adult;

class Library {
    protected:
        vector<Book*> catalog;
        vector<Member*> members;
    public:
        // Default constructor
        Library();

        // Destructor
        ~Library();

        // Getter
        vector<Book*> getCatalog() const;
        
        // Functions for book catalog

        void addBook(Book*&);
        // desc: adds pointer to Book object to catalog vector 
        // receives: Book*&
        // returns: nothing

        void deleteBook(string);
        // desc: deletes a pointer of Book from vector based on string title
        // receives: title as string
        // returns: nothing

        void updateBook(Book*&, string);
        // desc: updates pointer to Book object with new Book object based on if title matches
        // receives: Book*& as new object to replace old, and title as string
        // returns: nothing

        void searchBook(string);
        // desc: searches in vector for pointer to Book object by string title 
        // receives: title as string
        // returns: nothing

        void showBooks();
        // desc: shows all Books in vector
        // receives: nothing
        // returns: nothing

        // Functions for member list

        void addMember(Member*&);
        // desc: adds pointer to Member object to members vector 
        // receives: Member*& (pointer to Member object)
        // returns: nothing

        void deleteMember(string);
        // desc: deletes a pointer of Member from vector based on string name
        // receives: name as string
        // returns: nothing

        void updateMember(Member*&, string);
        // desc: updates pointer to Member object with new Member object based on if name matches
        // receives: Member*& as new object to replace old, and name as string
        // returns: nothing

        void searchMember(string);
        // desc: searches in vector for pointer to Member object by string name 
        // receives: name as string
        // returns: nothing

        void showMembers();
        // desc: shows all Members in vector: members
        // receives: nothing
        // returns: nothing
};

#endif