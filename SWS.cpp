#include<iostream>
using namespace std;

#define Max 100000

int main()
{
	/*S为单元环个数，K为多元环个数*/
	int a[Max],N,S=0,K=0,flag=0;
	cin>>N;
	int i,temp;
	for(i=0;i<N;++i){
		cin>>a[i];
		if(a[i]==i){
			if(i==0) flag=1;/*falg用于判断是否0在i==0的位置*/ 
			++S;
		}
	}
	
	for(i=0;i<N;++i)
		if(a[i]!=i){
			++K;
			while(a[i]!=i){
				temp=a[i];
				a[i]=i;
				i=temp;
			}
		}
	if(flag) cout<<N-S+K;
	else cout<<N-S+K-2;
}
