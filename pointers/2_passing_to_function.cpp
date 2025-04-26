#include <iostream>
using namespace std;

/*
as usual pointers can be passed by either value or reference
on passing by value, the original pointers will not change, but the value they were pointing to can change depending on function
on passing by reference, both pointers and value to which they are pointing can changes as per function
*/

// passing by value
void fun(int* p, int* q){
    // here p and q are passed by value- copies of original p and q, so even if p and q are updated( not the value they are pointing to), original p, q will remain same as earlier

    int* temp = p; // temp -> r
    p = q;      // p -> s
    q = temp;   // q -> r
    *temp = 2;   // r = 2;
}

//passing by reference
void fun2(int* &p, int* &q){
    // here original p and q will be updated

    int* temp = p; // temp -> r
    p = q;      // p -> s
    q = temp;   // q -> r
    *temp = 2;   // r = 2;
}



int main(){

    int r=20, s= 30;
    int* p = &r, *q = &s;

    fun(p,q);
    // p and q still point to r and s respectively as they are passed by value, but values they were pointing too are updated
    
    cout<<(*p)<<endl;   // r=2;
    cout<<(*q)<<endl;   // s= 30


    r=20, s=30;
    fun2(p,q);
    cout<<(*p)<<endl;   // s=30;
    cout<<(*q)<<endl;   // r= 2

    return 0;
}