#include <iostream>
#include <memory>
#include <atomic>
#include <vector>

using namespace std;

struct Base { virtual ~Base() {} };
struct Derived : Base {};

int main() {
    void* p = new Derived();
    //delete p;  // deleting using void pointer is undefined behaviour
    delete (Derived*)p; // this is correct way- or can use base class with proper virtual destructor, etc defined

    return 0;
}
