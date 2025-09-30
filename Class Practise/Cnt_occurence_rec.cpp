#include<iostream>
using namespace std;

int countOcc(string text,char alpha){
	static int count=0;
	static int idx=0;
	if(idx>=text.length()){
		return count;
	}
	if(text[idx]==alpha){
		count++;
	}
	idx++;
	return countOcc(text,alpha);
}

int main(){
	string text;
	char alpha;
	
	cout<<"Enter string: ";
	cin>>text;
	
	cout<<"Enter alphabet to found occurence: ";
	cin>>alpha;
	cout<<"The occurence of "<<alpha<<" is "<<countOcc(text,alpha);
}
