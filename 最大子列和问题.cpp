#include<iostream>
using namespace std;

int a[100000];

int main()
{
	int N;
	cin>>N;
	bool flag=false;
	for(int i=0;i<N;++i){
		cin>>a[i];
		if(a[i]>=0) flag=true;
	}
	if(!flag){
		printf("0 %d %d",a[0],a[N-1]);
		return 0;
	}
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
	cout<<MaxSum<<' '<<a[is]<<' '<<a[js];
	return 0;
} 
