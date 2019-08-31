#include<iostream>
using namespace std;

int H[1000],ing[1000],N;
bool G[1000][1000]={false},set[1000]={false};

int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&H[i]);
	}
	/*Âß¼­Í¼³õÊ¼»¯*/
	for(int i=0;i<N;++i)
	{
		if(H[i]<0) continue;
		if(H[i]%N!=i)
		{
			for(int j=H[i]%N;j!=i;j=(j+1)%N)
			{
				G[j][i]=true;
				++ing[i];
			}		
		}
	}
	/*ÍØÆËÅÅÐò¿ªÊ¼*/
	for(int i=0;i<N;++i)
		if(ing[i]==0&&H[i]>=0){
			set[i]=true;
		} 
	int u,min,flag=1,time=1;
	while(flag)
	{
		flag=0;
		u=-1;min=10000;
		for(int i=0;i<N;++i)
			if(set[i]&&H[i]<min){
				u=i;min=H[i];
			}
		if(time){time=0;cout<<H[u];}
		else cout<<' '<<H[u];
		set[u]=false;
		for(int i=0;i<N;++i)
			if(G[u][i]){
				--ing[i];
				if(ing[i]==0) set[i]=true;
			}
		for(int i=0;i<N;++i)
			if(set[i]) flag=1;
	}
	return 0; 
} 
