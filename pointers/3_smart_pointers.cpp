#include <iostream>
#include <memory>

using namespace std;

/*
while using pointers can lead to memory leaks and other problem. smart pointers are wrapper over pointer.
unique_ptr -> not copyable, only movable- use when not want to share ownership of pointer
shared_ptr-> both movable and copyable - object can be shared with many
weak_ptr -> can share object of shared_ptr but did not share ownership( reference count not incremented)

*/

class entity{
public:
    entity(){
        cout<<"entity created"<<endl;
    }
    ~entity(){
        cout<<"entity destroyed"<<endl;
    }
};


int main(){

    cout<<"shared"<<endl;
    {
        shared_ptr<entity> ptr0(new entity());   // not best practice- not safe- if exception is thrown during construction , could lead to memory leaks
    
        shared_ptr<entity> ptr = make_shared<entity>(); // automatically creates object on heap- internally calls new
        
        {
            shared_ptr<entity> ptr2= ptr;   // reference count increased to 2
        }
        //reference count decreased to 1

        shared_ptr<entity> ptr3= move(ptr); // ptr points to null
        cout<<(ptr == nullptr)<<endl; 

        {
            weak_ptr<entity> wptr= ptr3;    // reference count not increased
        }
    }


    cout<<endl;
    cout<<"unique"<<endl<<endl;
    {
        unique_ptr<entity> ptr(new entity()); // not safe
        unique_ptr<entity> ptr2= make_unique<entity>();
        //unique<ptr<entity> ptr3= ptr2 ; // error- not copyable
        unique_ptr<entity> ptr4 = move(ptr2);   // ptr2 is null now
        cout<<(ptr == nullptr)<<endl;
    }



    cout<<endl<<endl;
    cout<<"circular reference problem"<<endl<<endl;

    // circular reference problem - if two objecs holds shared pointer to each other, then reference never drops to zero causing memory leak
    // solution - weak pointer
    {
        class B;
        class A{
            public:
            shared_ptr<B> bptr;
            A(){
                cout<<"A created"<<endl;
            }
            ~A(){
                cout<<"A destroyed"<<endl;
            }
        };


        class B{
            public:
            shared_ptr<A> aptr;
            B(){
                cout<<"B created"<<endl;
            }
            ~B(){
                cout<<"B destroyed"<<endl;
            }
        };

        {
            shared_ptr<A> ptra= make_shared<A>();
            shared_ptr<B> ptrb= make_shared<B>();
            
            ptra->bptr = ptrb;
            ptrb->aptr = ptra; // circular dependency- problem start here
        }

        

    }


    // solution - using weak pointer in one of class
    cout<<endl<<"solution"<<endl;
    {
        class B;
        class A{
            public:
            shared_ptr<B> bptr;
            A(){
                cout<<"A created"<<endl;
            }
            ~A(){
                cout<<"A destroyed"<<endl;
            }
        };


        class B{
            public:
            weak_ptr<A> aptr;
            B(){
                cout<<"B created"<<endl;
            }
            ~B(){
                cout<<"B destroyed"<<endl;
            }
        };

        {
            shared_ptr<A> ptra= make_shared<A>();
            shared_ptr<B> ptrb= make_shared<B>();
            
            ptra->bptr = ptrb;
            ptrb->aptr = ptra; // circular dependency- problem start here
        }
    }




    return 0;
}