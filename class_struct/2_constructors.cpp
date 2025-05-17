#include <iostream>
using namespace std;

struct myclass {
    myclass() { std::cout << "Default\n"; }
    myclass(const myclass&) { std::cout << "Copy\n"; }
    myclass& operator=(const myclass&) { std::cout << "Copy assignment\n"; return *this; }
    myclass& operator=(myclass&&) { std::cout << "Move assignment\n"; return *this; }
    myclass(myclass&&) { std::cout << "Move\n"; }
};


myclass make_obj() {
    myclass obj;
    return obj;
}

int main() {

    // constructor is called when object is created
    myclass a;  // constructor
    cout<<"1"<<endl;
    myclass b = myclass();  // constructor after c++17( because of RVO), otherwise(in earlier c++ versions) constructor then move if available otherwise copy constructor
    cout<<"2"<<endl;


    // copy constructor is called when object is created from another object
    myclass d= myclass(a);  // copy constructor
    cout<<"3"<<endl;
    myclass e(a);       // copy constructor
    cout<<"4"<<endl;
    myclass f= a;       // copy constructor
    cout<<"5"<<endl;

    // copy assignmet is called when object is already created, but we call assignment with other already created class object
    d=b;    // copy assignment operator

    cout<<"6"<<endl;

    // move constructor is  forced by using move keyword
    myclass c = move(a);    // move converts object into rvalue, calling move forces move constructor not assignment

    cout<<"7"<<endl;
    // move assignment operator is called when object is already created, but we call assignment with new class object
    b = myclass();  // constructor for rhs side object; since it is rvalue, then move assignment operator is called
    
    // on rvalues , move constructor or move assignment operator is called based on it is assignment or constructor 


}
