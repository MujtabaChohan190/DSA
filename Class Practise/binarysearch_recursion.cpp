#include<iostream>
using namespace std;

int binarySearch(int* arr,int num,int left,int right){
	int mid=left+(right-left)/2;
	if(arr[mid]==num){
		return mid;
	}
	if(arr[mid]<num){
		return binarySearch(arr,num,mid+1,right);
	}
	if(arr[mid]>num){
		return binarySearch(arr,num,left,mid-1);
	}
	return -1;
}

int main(){
	int num;
	int arr[10]={1,2,33,43,55,69,76,98,101,432};
	cout<<"Enter num to find: ";
	cin>>num;
	cout<<"It is at index: "<<binarySearch(arr,num,0,9);
}
