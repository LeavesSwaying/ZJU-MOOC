#include<iostream>
#include<cmath>
using namespace std;

const int MaxN=20005;

int HashTable[MaxN];
int M,N;

bool isPrime(int n)
{
	/*判断素数的函数*/
	if(n<=1) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;++i)
		if(n%i==0) return false;
	return true;
} 

int prime[MaxN],pNum=0;
void findPrime()
{
	/*生成素数表*/
	for(int i=0;i<MaxN;++i)
		if(isPrime(i)==true){
			prime[pNum++]=i;
		}
}

bool F=false;
void insert(int x)
{
	int key=x%M;
	for(int i=0;i<=M/2;++i)
	{
		int y=(key+i*i)%M;
		if(HashTable[y]==-1)
		{
			HashTable[y]=x;
			if(F==false)
			{
				F=true;
			}
			else printf(" ");
			printf("%d",y);
			return;
		}
	}
	printf(" -");
}

int main()
{	
	//生成素数表，初始化Hash	
	findPrime();
	fill(HashTable,HashTable+MaxN,-1); 
	
	scanf("%d%d",&M,&N);
	if(isPrime(M)==false)
	{
		for(int i=0;i<pNum;++i)
			if(M<prime[i])
			{
				M=prime[i];
				break;
			} 
	}
	int a;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a);
		insert(a);
	}
	return 0;
} 
