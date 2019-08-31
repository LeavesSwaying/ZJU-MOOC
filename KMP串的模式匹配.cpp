#include<iostream>
#include<cstring>
using namespace std;
/*注意字符串长度比原来长度多1*/
#define SLEN 1000001
#define PLEN 100001

int main()
{
	char s[SLEN],p[PLEN];
	cin>>s;
	int N;
	cin>>N;
	while(N--)
	{
		cin>>p;
		char *k=strstr(s,p);
		if(k==NULL) cout<<"Not Found\n";
		else printf("%s\n",k);
	}
	return 0;
 } 
