#include <iostream>
#include <mutex>
#include <exception>
#include <string>
#include <thread>

using namespace std;


void func(int *arr){
	cout<<sizeof(arr)<<endl;	// will give 8- as here arr is considered as pointer which is 8 bytes
	// so we can't calculate size of array by sizeof(arr)/sizeof(arr[0])
}

// solution - we must pass it as array reference
void func2(int (&arr)[5]){
	cout<<sizeof(arr)<<endl;	// will give 20 , here arr is considered as array of five ints	
}




int main(){
	int arr[5]={0};

	cout<< sizeof(arr)/sizeof(arr[0])<<endl;	// 5- no of elements in array
	cout<<sizeof(arr)<<endl;	//20 - total size of array in bytes - here arr is considered as array not pointer

	func(arr);
	func2(arr);
    return 0;
}