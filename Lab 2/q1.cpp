#include<iostream>
using namespace std;

int main(){
	//Hardcoding the days
	int days = 7;
	int readings = 3;
	
	//Now creating 2d dynamic array
	int** temp = new int*[days];
	for(int i =0; i<7; i++){  //For each day , we have 3 readings
		temp[i] = new int[readings];
	}
	
	//Inputting the temperture
	cout<<"Input temperature for 7 days with 3 different readings of day"<<endl;
	for(int i = 0; i<days; i++){
		cout<<"Enter temperature for day: "<<i+1<<endl;
		for(int j=0; j<readings; j++ ){
			cin>>temp[i][j];
		}
	}
	//Hottest or coldest temp
	int hottest = temp[0][0];
	int coldest = temp[0][0];
	for(int i = 0; i<days; i++){
		for(int j =0; j<readings; j++){
			if(temp[i][j] > hottest){
				hottest = temp[i][j];
			}
			if(temp[i][j] < coldest){
				coldest = temp[i][j];
			}
		}
	}
	
	//Output results
	cout<<"The hottest temperature of the week is: "<<hottest<<endl;
	cout<<"The coldest temperature of the week is: "<<coldest<<endl;
	
	//Free Memory
	for(int i = 0; i<days; i++){
		delete[] temp[i];
	}
	delete[] temp;
	return 0;
}
