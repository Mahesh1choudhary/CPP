
#include <iostream>
#include <vector>
using namespace std;
/*
operator precedence and associativity- https://en.cppreference.com/w/cpp/language/operator_precedence
value of pointer changes based on the size of data type it points to - https://www.geeksforgeeks.org/cpp-pointer-arithmetic/

*/



int main(){
    
    int* p = new int[10]; // arr[10]
    for(int i=0;i<10;i++){
        if(i<=3) *(p+i)=i;
        else p[i] = i+10;
    }
    

    // currently p is pointing to 0 ( p -> arr[0]) the element of array
    cout<<"o1 "<<(*p)<<" "<<(*(p+1))<<endl; //arr[0] and arr[1];

    cout<<"o2 "<<(++*p)<<endl; // arr[0] +=1 p-> arr[0], output= arr[0]=1; - because of associativity from the order precedence
    p++;    // p -> arr[1];
    cout<<"o3 "<<(*p++)<<endl; // p = p+1 , p->arr[2], but dereferenced old p, so *p=arr[1]

    //delete[] p; - compiler error as p has been incremented and is not pointing to start of array- so will get compiler error
    // delete[] (p-2) - no error as p-2 points to start of array
    cout<<"o4 "<<(*p)++<<endl; // p still points to arr[2], prints arr[2]=2, and then updates arr[2] +=1 = 3;
    cout<<"o5 "<<(*p)<<endl;   // arr[2] = 3;
    cout<<"o6 "<<(*p++)++<<endl; // p -> arr[3], arr[3]+=1, but prints old arr[3]=3;
    cout<<"o7 "<<(*++p)<<endl;   // p -> arr[4], then dereferencing , arr[4]=14;
    cout<<"o8 "<<(++*p)<<endl;  // p -> arr[4], arr[4]+=1, prints new arr[4]=15;


    /*
    check order precedence and their associativy. Solve from highest precedence to lowest. Within same precedence group,
    solve as per associativity - whether left to right or right to left 
    */ 
    return 0;
}