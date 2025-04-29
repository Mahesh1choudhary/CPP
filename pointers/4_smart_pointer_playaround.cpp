#include <iostream>
#include <memory>
#include <atomic>
#include <vector>

using namespace std;

int main(){

    // arithmetic operations are not allowed on smart pointers as they are contianers
    {
        //unique_ptr<int> arr(new int[5]);    // incorrect - internally shared and unique ptr calls delete, not delete[]
        unique_ptr<int[]> arr= make_unique<int[]>(5);
        for(int i=0;i<5;i++){
            arr[i]= i;
            //*(arr+i)=i; - not supported
        }

    }

    // aliasing shared_ptr - different shared pointers can use same object , but points to difference part of object - but all share the reference count( increases every time)
    {
        struct obj{
            int val;
            double d;
            vector<int> v{5};
        };
        auto ptr1 = make_shared<obj>();
        shared_ptr<int> ptr2(ptr1, &ptr1->val); // ptr1 and 2 share the ref count, but ptr2 points only to subobject
        *ptr2 = 10;
        cout<<(ptr1->val)<<endl;
        cout<< ptr1.use_count()<<endl;  // returns 2

        shared_ptr<int> ptr3(ptr1, &(ptr1->v)[2]);
        *ptr3 = 10;
        cout<< ptr1.use_count()<<endl;  // returns 3

        cout<<(ptr1->v)[2]<<endl;   // return 10


    }
    cout<<endl<<"atomic smart pointers"<<endl;

    // atomic shared ptr
    /*
    since smart pointers are not "trivially" copyable- which is condition for datatype to be atomic- we cannot create atomic smart pointers
    
    throws error
    {
        atomic<unique_ptr<int>> ptr;
        ptr.store(make_unique<int>(5));
        cout<< *(ptr.load())<<endl;
    }

    */


    return 0;
}