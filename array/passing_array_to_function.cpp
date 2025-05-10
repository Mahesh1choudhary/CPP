#include <iostream>
#include <mutex>
#include <exception>
#include <string>
#include <thread>

using namespace std;

// No matter what notation we use, array will still be passed as pointer due to array decay

void func(int arr[5]){
    cout<<arr[0]<<endl;

	cout<<sizeof(arr)<<endl;	// will give 8- as here arr is considered as pointer which is 8 bytes
}

void func2(int arr[]){
    cout<<arr[0]<<endl;

	cout<<sizeof(arr)<<endl;	// 8	
}

// the array decay can only be solved by specifically mentioned/passing by reference


int main(){
	int arr[5]={0};
    arr[0]=10;
	cout<< sizeof(arr)/sizeof(arr[0])<<endl;	// 5- no of elements in array
	cout<<sizeof(arr)<<endl;	//20 - total size of array in bytes - here arr is considered as array not pointer


	cout<<"passing to function"<<endl;
    
	func(arr);
	func2(arr);
    return 0;
}