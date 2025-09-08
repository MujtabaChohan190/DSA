#include<iostream>
using namespace std;

int main(){
	int n;
	double balance = 0.0;
	cout<<"Enter the number of transactions: "<<endl;
	cin>>n;
	double* arr = new double[n];
	for(int i = 0; i < n; i++){
		cout<<"Enter the transaction amount:"<<endl;
		cin>>arr[i];
		cout<<endl;
	}
	
	for(int i = 0; i<n; i++){
		balance+= arr[i];		
	}
	cout<<"total balance is:"<<balance<<endl;
	return 0;
}
