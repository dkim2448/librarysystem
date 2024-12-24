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
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Adult.h"
using namespace std;

// Default constructor
Adult::Adult() : Member(){

}

// Fully parameterized constructor
Adult::Adult(string name = "", int age = 0, int cardNumber = 0) : Member(name, age, cardNumber){

}

// Virtual function that determines access of library, full access (Adult)
void Adult::sectionAccess(){
    cout << getName() << ", You have access to all sections of the library." << endl;
}