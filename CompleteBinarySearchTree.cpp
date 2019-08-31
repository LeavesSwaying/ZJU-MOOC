#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int Tree[1000],Data[1000];

int GetLeftLength(int n)
{
	double h,x,L,t;
	h=(double)(int)(log((double)n+1)/log(2.0));
	x=n-pow(2.0,h)+1;
	t=pow(2.0,h-1.0);
	x=x<t?x:t;
	L=t-1+x;
	return (int)L;
}

void solve(int DLeft,int DRight,int TRoot){
	int n,l;
	n=DRight-DLeft+1;
	if(!n) return;
	l=GetLeftLength(n);
	Tree[TRoot]=Data[DLeft+l];
	solve(DLeft,DLeft+l-1,2*TRoot+1);
	solve(DLeft+l+1,DRight,2*TRoot+2);
}

int main()
{
	int k,N;
	cin>>N;
	for(int i=0;i<N;++i) cin>>Data[i];
	sort(Data,Data+N);
	
	solve(0,N-1,0);
	
	for(int i=0;i<N;++i){
		if(!i) cout<<Tree[i];
		else cout<<' '<<Tree[i];
	}
	return 0;
 } 
