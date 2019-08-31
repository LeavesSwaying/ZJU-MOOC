#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int G[100][100],N,M;
int dis[100],pre[100],ing[100];

void FindPath(int end)
{
	
	int start,start0,end0;
	start=pre[end];
	if(pre[start]==-1){
		start0=start+1;end0=end+1;
		cout<<start0<<"->"<<end0<<endl;
		return;
	}
	FindPath(start);
	start0=start+1;end0=end+1;
	cout<<start0<<"->"<<end0<<endl;
}
 
void TopSort()
{
	int i;
	queue<int> q;
	fill(dis,dis+N,-1);
	fill(pre,pre+N,-1);
	for(i=0;i<N;++i)
		if(ing[i]==0){
			q.push(i);
			dis[i]=0;
		}
	int u;
	while(q.size())
	{
		u=q.front();q.pop();
		for(int i=0;i<N;++i)
			if(G[u][i]){
				ing[i]--;
				if(ing[i]==0)
					q.push(i);
				if(dis[u]+G[u][i]>dis[i]){
					dis[i]=dis[u]+G[u][i];
					pre[i]=u;
				}
			}
	}
	int max=-1;
	for(i=0;i<N;++i){
		if(ing[i]!=0) break;
		else if(max<dis[i])
		{
			u=i;max=dis[i];
		}
	}
	if(i==N) cout<<max<<endl;
	else{
		cout<<"0";
		return;
	}
	FindPath(u); 	
}

int main()
{
	cin>>N>>M;
	int a,b,c;
	while(M--){
		cin>>a>>b>>c;
		a--;b--;
		G[a][b]=c;ing[b]++;
	}
	TopSort();
}
