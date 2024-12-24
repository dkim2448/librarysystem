// *******************************************************
// Name      :  <Daniel Kim>
// Class     :  CSCI 2312 Section 002  
// Project   :  Project 1
// 
// For compiling you can copy and paste this: 
// (g++ .\src\Library.cpp .\src\Book.cpp .\src\main.cpp .\src\Member.cpp .\src\Adult.cpp .\src\Child.cpp)
// *******************************************************

#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Adult.h"
#include "Child.h"
using namespace std;

int main(){
    // Creating library
    Library library;

    // Creating and adding book (The Hunger Games) to the library
    Book* book1 = new Book("The Hunger Games", "Suzanne Collins", "9780439023481", 2008);
    library.addBook(book1);

    // Creating book to update it in library using updateBook()
    Book* book2 = new Book("UPDATED: Garfield at Large", "UPDATED AUTHOR", "UPDATED ISBN", 123);

    try{
        // Deleting book (Diary of a Wimpy Kid) from library
        library.deleteBook("Diary of a Wimpy Kid");

        // Updating book (Garfield at Large) w/ information of book2
        library.updateBook(book2, "Garfield at Large");

        // Searching for book (Calvin and Hobbes) in library
        cout << "TESTING SEARCHBOOK() FUNCTION:" << endl;
        library.searchBook("The Essential Calvin and Hobbes");

        // Testing error handling: should show message "Error! Book not found in search!"
        library.searchBook("Non-existent book");
    }
    catch(string ex){
        cout << ex << endl;
    }

    // Showing book list
    library.showBooks();

    // Creating and adding adult member (Daniel) to members list
    Member* member1 = new Adult("Daniel", 21, 200);
    library.addMember(member1);

    // Creating child member (Patrick) to update it using updateMember()
    Member* member2 = new Child("Patrick (updated)", 12, 202);

    try{
        // Deleting member (Spongebob) from members list
        library.deleteMember("SpongeBob");

        // Updating member with member2
        library.updateMember(member2, "Patrick");

        // Searching for member (Sandy) in members
        cout << "TESTING SEARCHMEMBER() FUNCTION:" << endl;
        library.searchMember("Sandy");

        // Testing error handling: should show message "Error! Name of member not found in search!"
        library.searchMember("Non-existent name");
    }
    catch(string error){
        cout << error << endl;
    }

    // Showing member list
    library.showMembers();

    try {
        // Borrowing and returning books from library
        member1->borrowBook("The Essential Calvin and Hobbes", library);
        member1->borrowBook("Big Nate: From the Top", library);
        member1->borrowBook("The Fault in Our Stars", library);
        member1->returnBook("The Essential Calvin and Hobbes");

        cout << "Late fee estimate: $" << member1->getLateFees() << endl;

        // Showing borrowing list/report
        member1->viewBorrowed();

        // Testing error handling: should show message "Error! Book not returned! Title not found!"
        member1->returnBook("Non-existent book");
        
    }
    catch(string ex){
        cout << ex << endl;
    }

    // Seeing if member has access to library based on if Child or Adult
    member1->sectionAccess();
    member2->sectionAccess();

    // Deleting dynamically allocated pointers
    delete book1;
    delete book2;
    delete member1;
    delete member2;

    return 0;
}