#include<iostream>
using namespace std;

int B[51];

int main(){
	int temp,N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>temp;
		B[temp]++;
	}
	for(int i=0;i<51;++i){
		if(B[i]){
			cout<<i<<":"<<B[i]<<endl;
		}
	}
	return 0;
} 
