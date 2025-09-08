#include<iostream>
using namespace std;

int main(){
    int size = 7;
    double* arr;
    arr = new double[size]; //allocating an array of double
    double sum = 0;

    for(int i=0; i<size ; i++){
        cout<<"Input temperature of day"<<i+1<<endl;
        cin>>arr[i];
    }

    cout<<"Temperature of the week"<<endl;
    for(int i = 0; i<size; i++){
        cout<<"Temperature of day"<<(i+1)<<"is :"<<arr[i]<<endl;
        sum+= arr[i];
    }

    double avg = sum/size;
    cout<<"Average temperature of week is:"<<avg<<endl;

    //Freeing memory
    delete[] arr;

    return 0;

}