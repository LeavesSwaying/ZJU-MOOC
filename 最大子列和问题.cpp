#include<iostream>
using namespace std;

int a[100000];

int main()
{
	int d,N;
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>a[i];
	int sum,MaxSum=-1;
	int is,js;
	for(int i=0;i<N;++i){
		sum=0;
		for(int j=i;j<N;++j){
			sum+=a[j];
			if(MaxSum<sum){
				is=i;
				js=j;
				MaxSum=sum;
			}
			
		}
	} 
	cout<<MaxSum<<' '<<is<<' '<<js;
	return 0;
} 
