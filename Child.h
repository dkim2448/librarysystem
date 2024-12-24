/* *******************************************************

 * This header file provides a class declaration for the
 * Child class. It consists of constructors and a virtual
 * function to determine section access. This is a 
 * derived class for the base class Member.
 * 
 * *******************************************************/

#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"
using namespace std;

class Child : public Member {
    public:
        // Default constructor
        Child();

        // Fully parameterized constructor
        Child(string, int, int);

        virtual void sectionAccess(); 
        // desc: virtual void function that determines section access of library,
        //       there's IS NOT full access because this is a Child class
        // receives: nothing
        // returns: nothing
};

#endif