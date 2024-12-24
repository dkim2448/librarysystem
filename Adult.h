/* *******************************************************

 * This header file provides a class declaration for the
 * Adult class. It consists of constructors and a virtual
 * function to determine section access. This is a 
 * derived class for the base class Member.
 * 
 * *******************************************************/

#ifndef ADULT_H
#define ADULT_H

#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"
using namespace std;

class Adult : public Member {
    public:
        // Default constructor
        Adult();

        // Fully parameterized constructor
        Adult(string, int, int);

        virtual void sectionAccess();
        // desc: virtual void function that determines section access of library,
        //       there's full access because this is an Adult class
        // receives: nothing
        // returns: nothing
};

#endif