
#include <iostream>

using namespace std;

void fun(int *x, int  *y){
	*x =1, *y=2; // x->a, y->b , so a=1, b=2;
    int* temp = x;
	x =y; // x->b
	*y=3;   // a=1, b=3;
	*x =10; // a=1, b=10;

    *temp = 5;  // a=5;
}


int main(){
	int a=5, b=6;
	fun(&a,&b);
	cout<<a<<" "<<b<<endl;

    return 0;
}