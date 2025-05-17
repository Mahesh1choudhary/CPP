
/*
static allocation of array with non-const or size unknown at compile time is not possible
but dynamic alloaction is possible
*/

int main(){
    int n=10;   // or n is not known , cin>>n

    //int arr[n]; // gives error as n must be const

    int* p = new int[n];    // no error

    return 0;
}