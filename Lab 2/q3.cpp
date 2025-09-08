#include<iostream>
using namespace std;

int main(){
	//Since we dont know the number of patients ie rows
	int n ;
	cout<<"Enter the number of patients: "<<endl;
	cin>> n;
	int** arr = new int*[n]; //dynamically allocating the 2d array
	int* size = new int[n]; //making array to store varied number of medicines of each patient - in case of fixed size we can use size[3] but in case of varied we do dma
	
	//Now storing different number of medicines of each patient in size array
	for(int i = 0; i < n; i++){
		cout<<"Enter the number of medicines of  patients"<<endl;
		cin>>size[i];
		//now we will allocate each row with different sizes - thats why we made 2d array there 
		arr[i] = new int[size[i]];
	}
	
	//now storing the medicines data of each row 
	for(int i = 0; i<n; i++){
		for(int j = 0; j < size[i]; j++){ //each patient has varied medicines , so we stored it in size[i] and hence used it as cols of jagged array
			arr[i][j] = j+ 1;
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j < size[i]; j++){
			cout<<arr[i][j]<<endl;
		}
		cout<<endl;
	}
	
	//Freeing the memory 
	for(int i = 0; i<n; i++){
		delete[] arr[i];
	}
	delete[] arr;
	delete[] size;
	
	return 0;

}

