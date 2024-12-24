/*********************************************************
* Summary: This file includes the implementation for the 
* Library.h class (defined in Library.h).
*
* Author: Daniel Kim
* Created: November 15, 2024
* Summary of Modifications [if applicable]:
*      28 Nov 2024 – Completed Project 1
*      25 Nov 2024 – Created header and implemention files
*
********************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <iomanip>
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Adult.h"
using namespace std;

// Instantiates Library, adding information to vectors from files
Library::Library(){
    // Adding books to vector: catalog from file
    ifstream fin;
    fin.open("data/catalog.txt");
    
    if(fin.is_open()){
        string line;
        while(getline(fin, line)){
            stringstream ss(line);
            
            string title;
            string author;
            string ISBN;
            int pubYear;
            string temp;

            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, ISBN, ',');
            getline(ss, temp);
            pubYear = stoi(temp);

            Book* book = new Book;
            book->setTitle(title);
            book->setAuthor(author);
            book->setISBN(ISBN);
            book->setPubYear(pubYear);

            catalog.push_back(book);
        }

        fin.close();
    }
    else {
        string ex = "Error! Catalog file not found!\n";
        throw ex;
    }

    // Adding members to vector: members from file
    ifstream inFile;
    inFile.open("data/members.txt");
    
    if(inFile.is_open()){
        string line;
        while(getline(inFile, line)){
            stringstream ss(line);
            
            string name;
            int age;
            int cardNumber;
            string temp;

            getline(ss, name, ',');
            getline(ss, temp, ',');
            age = stoi(temp);
            getline(ss, temp);
            cardNumber = stoi(temp);

            Member* member = new Adult;
            member->setName(name);
            member->setAge(age);
            member->setCardNumber(cardNumber);

            members.push_back(member);
        }

        inFile.close();
    }
    else {
        string ex = "Error! Member list file not found!\n";
        throw ex;
    }
}

// Destructor
Library::~Library(){
    // deleting pointers from vector
    for(int i = 0; i < catalog.size(); i++){
        delete catalog[i];
    }

    for(int i = 0; i < members.size(); i++){
        delete members[i];
    }
}

// Getter
vector<Book*> Library::getCatalog() const {
    return catalog;
}

// For books vector and Book class

// Adds pointer to Book object to catalog vector 
void Library::addBook(Book* &newBook){
    catalog.push_back(newBook);
}

// Deletes a pointer of Book from vector based on string title
void Library::deleteBook(string title){
    for(int i = 0; i < catalog.size(); i++){
        if(catalog[i]->getTitle() == title){
            delete catalog[i];
            catalog.erase(catalog.begin() + i);
            return;
        }
    }

    string ex = "Error! Title to delete book not found!\n";
    throw ex;
}

// Updates pointer to Book object with new Book object based on if title matches
void Library::updateBook(Book* &book, string title){
    for(int i = 0; i < catalog.size(); i++){
        if(catalog[i]->getTitle() == title){
            catalog[i]->setTitle(book->getTitle());
            catalog[i]->setAuthor(book->getAuthor());
            catalog[i]->setISBN(book->getISBN());
            catalog[i]->setPubYear(book->getPubYear());
            return;
        }
    }

    string ex = "Error! Title to update book not found!\n";
    throw ex;
}

// Searches in vector for pointer to Book object by string title
void Library::searchBook(string title){
    for(int i = 0; i < catalog.size(); i++){
        if(catalog[i]->getTitle() == title){
            cout << setw(34) << setfill('-') << "" << endl;
            cout << "BOOK FOUND:" << endl;
            cout << "Title: " << catalog[i]->getTitle() << endl;
            cout << "Author: " << catalog[i]->getAuthor() << endl;
            cout << setw(34) << setfill('-') << "" << endl;
            return;
        }
    }

    string ex = "Error! Book not found in search!\n";
    throw ex;
}

// Shows all Books in vector
void Library::showBooks(){
    vector<Book*>::iterator it;
    int count = 1;
    cout << "LIST OF BOOKS" << endl;
    cout << setw(34) << setfill('-') << "" << endl;
    for(it = catalog.begin(); it != catalog.end(); it++){
        cout << "BOOK " << count << ": " << endl;;
        cout << "Title: " << (*it)->getTitle() << endl;
        cout << "Author: " << (*it)->getAuthor() << endl;
        cout << "ISBN: " << (*it)->getISBN() << endl;
        cout << "Publishing Year: " << (*it)->getPubYear() << endl;
        cout << endl;
        count++;
    }
}

// For Members class and members vector

// Adds pointer to Member object to members vector 
void Library::addMember(Member*& member){
    members.push_back(member);
}

// Deletes a pointer of Member from vector based on string name
void Library::deleteMember(string name){
    for(int i = 0; i < members.size(); i++){
        if(members[i]->getName() == name){
            delete members[i];
            members.erase(members.begin() + i);
        }
        return;
    }

    string ex = "Error! Member to delete not found!\n";
    throw ex;
}

// Updates pointer to Member object with new Member object based on if name matches
void Library::updateMember(Member*& member, string name){
    for(int i = 0; i < members.size(); i++){
        if(members[i]->getName() == name){
            members[i]->setName(member->getName());
            members[i]->setAge(member->getAge());
            members[i]->setCardNumber(member->getCardNumber());
            return;
        }
    }

    string ex = "Error! Name to update member not found!\n";
    throw ex;
}

// Searches in vector for pointer to Member object by string name 
void Library::searchMember(string name){
    for(int i = 0; i < members.size(); i++){
        if(members[i]->getName() == name){
            cout << setw(34) << setfill('-') << "" << endl;
            cout << "MEMBER FOUND:" << endl;
            cout << "Name: " << members[i]->getName() << endl;
            cout << "Age: " << members[i]->getAge() << endl;
            cout << "Card Number: " << members[i]->getCardNumber() << endl;
            cout << setw(34) << setfill('-') << "" << endl;
            return;
        }
    }

    string ex = "Error! Name of member not found in search!\n";
    throw ex;
}

// Shows all Members in vector: members
void Library::showMembers(){
    vector<Member*>::iterator it;
    int count = 1;
    cout << "LIST OF MEMBERS" << endl;
    cout << setw(34) << setfill('-') << "" << endl;
    for(it = members.begin(); it != members.end(); it++){
        cout << "MEMBER " << count << ": " << endl;;
        cout << "Name: " << (*it)->getName() << endl;
        cout << "Age: " << (*it)->getAge() << endl;
        cout << "ID: " << (*it)->getCardNumber() << endl;
        cout << endl;
        count++;
    }
}
