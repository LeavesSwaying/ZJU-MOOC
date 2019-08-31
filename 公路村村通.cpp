#include<iostream>
using namespace std;

const int inf=10000;

int G[1001][1001],N,M;
int set[1001],dist[1001];

int Prime(int v0){
	int i,j,v,min,sum=0;
	for(i=0;i<N+1;++i){
		dist[i]=G[v0][i];
	}
	set[v0]=1;
	for(i=2;i<N+1;++i){
		min=inf;
		for(int j=1;j<N+1;++j)
			if(!set[j]&&dist[j]<min){
				v=j;
				min=dist[j];
			}
        if(min==inf) return -1;
		set[v]=1;
		sum+=min;
		for(int j=1;j<N+1;++j){
			if(!set[j]&&G[v][j]<dist[j]){
				dist[j]=G[v][j];
			}
		}
	}
	return sum;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N+1;++i)
		for(int j=0;j<N+1;++j)
			G[i][j]=inf;
	int a,b,c;
	for(int i=0;i<M;++i){
		cin>>a>>b>>c;
		G[a][b]=G[b][a]=c;
	}
	int k;
	k=Prime(1);
	cout<<k;
	return 0;
} 
