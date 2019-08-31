#include<iostream>
#include<cstring>
using namespace std;

const int inf=1000;

int G[550][550];
int P[550][550];
int set[550];
int dist[550];
int cost[550];
int N,M,S,D;

void BuildGraph(){
	cin>>N>>M>>S>>D;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			G[i][j]=P[i][j]=inf;
		}
	int a,b,c,d;
	for(int i=0;i<M;++i){
		cin>>a>>b>>c>>d;
		G[a][b]=G[b][a]=c;
		P[a][b]=P[b][a]=d;
	}
}
void Dijkstra(int start)
{
	int i,j,v,min;
	for(i=0;i<N;++i){
		dist[i]=G[start][i];
		cost[i]=P[start][i];
	}
	set[start]=1;
	dist[start]=0;cost[start]=0;
	for(i=1;i<N;++i){
		min=inf;
		for(j=0;j<N;++j){
			if(!set[j]&&dist[j]<min){
				min=dist[j];
				v=j;
			}
		}
		set[v]=1;
		for(j=0;j<N;++j)
			if(!set[j]){
				if(G[v][j]+dist[v]<dist[j]){
					dist[j]=G[v][j]+dist[v];
					cost[j]=P[v][j]+cost[v];
				}
				else if(dist[v]+G[v][j]==dist[j]&&cost[v]+P[v][j]<cost[j])
					cost[j]=cost[v]+P[v][j];
			}
		
	}
}
int main()
{
	memset(set,0,sizeof(set));
	BuildGraph();
	Dijkstra(S);
	cout<<dist[D]<<' '<<cost[D];
	return 0;
}
