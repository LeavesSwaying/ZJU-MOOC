#include<iostream>
#include<cstring>
using namespace std;
/*ע���ַ������ȱ�ԭ�����ȶ�1*/
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
