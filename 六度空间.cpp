#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int G[10001][10001], set[10001], N, M;

int BFS(int start) {
	int temp, count, level, last, tail;
	queue<int> q;
	q.push(start);
	set[start] = 1;
	count = 1;
	level = 0; last = start;
	while (q.size()) {
		temp = q.front();
		q.pop();
		for (int i = 0; i < N; ++i)
			if (G[temp][i] && !set[i]) {
				set[i] = 1;
				q.push(i);
				count++;
				tail = i;
			}
		if (temp == last) {
			level++;
			last = tail;
		}
		if (level == 6) break;
	}
	return count;
}

int main()
{
	int a, b, r;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		G[a-1][b-1] = G[b-1][a-1] = 1;
	}
	double rat;
	for (int i = 0; i < N; ++i) {
		fill(set, set + N, 0);
		r = BFS(i);
        /* 下面rat的形式对答案很关键*/
		rat = r*1.0/ N*100;
		printf("%d: %.2lf%%\n",i+1,rat);
	}
}

