#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int G[10][10],set[10],N;

void DFS(int start)
{
	set[start]=1;
	
	cout<<start<<' ';//Í¼±éÀú²Ù×÷ 
	
	for(int i=0;i<N;++i)
		if(G[start][i]&&!set[i])
			DFS(i);
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	set[start]=1;
	while(q.size()){
		int d=q.front();
		q.pop();
		cout<<d<<' ';
		for(int i=0;i<N;++i)
			if(G[d][i]&&!set[i]){
				set[i]=1;
				q.push(i);
			}
	}

}

int main()
{
	int start,final,E;
	cin>>N>>E;
	for(int i=0;i<E;++i){
		cin>>start>>final;
		G[start][final]=G[final][start]=1;
	}
	for(int i=0;i<N;++i)
		if(!set[i]){
			cout<<"{ ";
			DFS(i);
			cout<<"}\n";
		}
	cout<<"\n";
	fill(set,set+N,0);
	for(int i=0;i<N;++i)
		if(!set[i]){
			cout<<"{ ";
			BFS(i);
			cout<<"}\n";
		} 
	return 0;
 } 
