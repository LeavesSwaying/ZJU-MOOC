#include<iostream>
#include<stack>
#include<queue> 
using namespace std;

bool Judge(int length, int size)
{
	stack<int> s;
	queue<int> q,tmp;
	int temp;
	for (int i = 0; i < length; ++i) {
		q.push(i + 1);
		cin >> temp;
		tmp.push(temp);
	} 
	for (int i = 0; i<length; ++i) {
		temp = tmp.front();
		tmp.pop();
		if (q.size()&&(q.front() <= temp))
			for (int j = q.front() - 1; j<temp; ++j) {
				s.push(q.front());
				q.pop();
				if (size<s.size()) return false;
			}
		if (temp!=s.top()) return false;
		s.pop();
	}
	return true;
}

int main()
{
	int s_length, N, K;
	cin >> s_length >> N >> K;
	for (int i = 0; i<K; ++i) {
		if (Judge(N, s_length)) cout << "YES\n";
		else cout << "No\n";
	}
}
