#include<iostream>
#include<algorithm>
using namespace std;

int G[100][100], D[100][100], path[100][100], N, M;

const int inf = 10000;

void Floyd()
{
	int i, j, k;
	for (i = 0; i<N; ++i)
		for (j = 0; j<N; ++j) {
			D[i][j] = G[i][j];
			path[i][j] = -1;
		}
	for (k = 0; k<N; ++k)
		for (i = 0; i<N; ++i)
			for (j = 0; j<N; ++j)
				if (D[i][k] + D[k][j]<D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;
				}
}

int main()
{
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (i == j) G[i][j] = 0;
			else G[i][j] = inf;
	for (int i = 0; i<M; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		G[a][b] = G[b][a] = c;
	}
	Floyd();
	int max,min,index=0;
	min=inf;
	for(int i=0;i<N;++i){
		max=0;
		for(int j=0;j<N;++j){
			if(max<D[i][j])
				max=D[i][j];
		}
		if(min>max){
			min=max;
			index=i+1;
		}
	}
	if(index==0) cout<<0<<endl;
	else cout<<index<<' '<<min;
	return 0;
}
