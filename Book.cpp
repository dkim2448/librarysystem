#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "Member.h"
using namespace std;

// Default constructor
Book::Book(){
    this->title = "";
    this->author = "";
    this->ISBN = "";
    this->pubYear = 0;
}

// Fully parameterized constructor
Book::Book(string title, string author, string ISBN, int pubYear){
    setTitle(title);
    setAuthor(author);
    setISBN(ISBN);
    setPubYear(pubYear);
}

// Getters
string Book::getTitle() const{
    return title;
}

string Book::getAuthor() const{
    return author;
}

string Book::getISBN() const{
    return ISBN;
}

int Book::getPubYear() const{
    return pubYear;
}

// Setters
void Book::setTitle(string title){
    this->title = title;
}

void Book::setAuthor(string author){
    this->author = author;
}

void Book::setISBN(string ISBN){
    this->ISBN = ISBN;
}

void Book::setPubYear(int pubYear){
    this->pubYear = pubYear;
}
