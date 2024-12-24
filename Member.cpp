/*********************************************************
* Summary: This file includes the implementation for the 
* Adult.h class (defined in Adult.h).
*
* Author: Daniel Kim
* Created: November 15, 2024
* Summary of Modifications [if applicable]:
*      28 Nov 2024 – Completed Project 1
*      25 Nov 2024 – Created header and implemention files
*
********************************************************/

#include <iostream>
#include <iomanip>
#include "Member.h"
#include "Library.h"
#include "Book.h"
using namespace std;

// Default constructor
Member::Member(){
    this->name = "";
    this->age = 0;
    this->cardNumber = 0;
}

// Full parameterized constructor
Member::Member(string name, int age, int cardNumber){
    setName(name);
    setAge(age);
    setCardNumber(cardNumber);
}

// Getters
string Member::getName() const {
    return name;
}

int Member::getAge() const {
    return age;
}

int Member::getCardNumber() const {
    return cardNumber;
}

int Member::getLateFees() const {
    int lateFees = booksBorrowed.size() * 5;
    return lateFees;
}

// Setters
void Member::setName(string name){
    this->name = name;
}

void Member::setAge(int age){
    this->age = age;
}

void Member::setCardNumber(int cardNumber){
    this->cardNumber = cardNumber;
}

// Functions

// Adds Book from Library catalog to booksBorrowed vector based on title
void Member::borrowBook(string title, Library& library){
    for(auto book : library.getCatalog()){
        if(book->getTitle() == title){
            booksBorrowed.push_back(book);
            return;
        }
    }

    string ex = "Error! Title of book to borrow not found!\n";
    throw ex;
}

// Deletes a pointer of Book from booksBorrowed based on string title
void Member::returnBook(string title){
    for(int i = 0; i < booksBorrowed.size(); i++){
        if(booksBorrowed[i]->getTitle() == title){
            delete booksBorrowed[i];
            booksBorrowed.erase(booksBorrowed.begin() + i);
            return;
        }
    }

    string ex = "Error! Book not returned! Title not found!\n";
    throw ex;
}

// Shows all Books borrowed from vector booksBorrowed
void Member::viewBorrowed(){
    cout << "LIST OF BORROWED BOOKS" << endl;
    cout << setw(34) << setfill('-') << "" << endl;
    for(Book* book : booksBorrowed){
        cout << "Title: " << book->getTitle() << endl;
        cout << "Author: " << book->getAuthor() << endl;
        cout << "ISBN: " << book->getISBN() << endl;
        cout << "Publishing Year: " << book->getPubYear() << endl;
        cout << endl;
    }
}

