#include<iostream>
using namespace std;

int S[10000], n;

int Find(int X)
{
	for (; S[X] >= 0; X = S[X]);
	return X;
}
void Union(int Root1, int Root2)
{
    if(S[Root1]>S[Root2]) S[Root1]=Root2;
	else{
        if(S[Root1]==S[Root2]) S[Root1]--;
        S[Root2] = Root1;
    } 
}

void Input_connection(int n)
{
	int u, v;
	int Root1, Root2;
	cin >> u >> v;
	Root1 = Find(u - 1);
	Root2 = Find(v - 1);
	if (Root1 != Root2)
		Union(Root1, Root2);
	return;
}
void Check_connection(int n)
{
	int u, v;
	int Root1, Root2;
	cin >> u >> v;
	Root1 = Find(u - 1);
	Root2 = Find(v - 1);
	if (Root1 != Root2)
		printf("no\n");
	else printf("yes\n");
	return;
}
void Check_network(int n)
{
	int i, counter = 0;
	for (i = 0; i<n; ++i)
		if (S[i]<0) counter++;
	if (counter == 1) printf("The network is connected.\n");
	else printf("There are %d components.\n", counter);
	return;
}
int main()
{
	for (int i = 0; i < 10000; i++) S[i] = -1;
	char in;
	cin>>n;
	do {
		cin>>in;
		switch (in) {
		case 'I': Input_connection(n); break;
		case 'C': Check_connection(n); break;
		case 'S': Check_network(n); break;
		}
	} while (in != 'S');
	return 0;
}
