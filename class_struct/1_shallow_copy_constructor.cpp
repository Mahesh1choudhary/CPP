#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/* this programs gives error - Double free of object {memory_location}

Reason - str is on heap , and we did not provide copy constructor in class A, so the compiler generated copy constructor/ copy assignment operator will
be used.
in class B, we are doign "innerc = A(s);"
we create temporary obejct of A, copy it to innerc, but since compiler generated copy assignment operator will be called, so only shallow copy is made
so both innerc and the temporry object point to same memory location in str
when constructor of B ends, temporary object of A is deleted, which deletes the str memory, so when the main function ends, the B object is deleted, which also calls destructor
on innerc, so it again tries to delete the same str memory location, hence the error

solution - define copy constructor and operator to do deep copy, in class A
this should be done in every class , which has pointers, references as membe functions
*/

const int base_size = 100000l;

class A {
public:
   A() {
       str = new char[base_size];
   }
   A(uint s) {
       str = new char[s];
   } 

   ~A() {
       delete[] str;
       str = nullptr;
   }


private:
   char *str;
};


class B {
public:
   B(uint s) {
    innerc = A(s);
   }

   ~B() {}

private:
   A innerc;
};

int main() {
   uint n = 100;
   B outerc(n);
   return 0;
}
