/*********************************************************
* Summary: This file includes the implementation for the 
* Child.h class (defined in Child.h).
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
#include "Child.h"
using namespace std;

// Default constructor
Child::Child() : Member(){

}

// Fully parameterized constructor
Child::Child(string name, int age, int cardNumber) : Member(name, age, cardNumber){

}

// Virtual function that determines access of library, partial access (Child class)
void Child::sectionAccess(){
    cout << getName() << ", You DO NOT have access to all sections of the library." << endl;
}