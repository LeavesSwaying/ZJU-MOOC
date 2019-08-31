#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 10000
typedef struct HTable
{
	int *list;
	int  size;
}HTable,*HashTable;

HashTable CreatTable(int n);
int Insert(HashTable H,int num);
int NextPrime(int n);

int main()
{
	int i,m,n,num;
	int pos[N];
	HashTable H;
	scanf("%d%d",&m,&n);
	H=CreatTable(m);
	for(i=0;i<n;++i){
		scanf("%d",&num);
		/*pos[]�洢����λ��*/
		pos[i]=Insert(H,num);
	} 
	if(n){
		printf("%d",pos[0]);
		for(i=1;i<n;++i){
			if(pos[i]==-1) printf(" -");
			else printf(" %d",pos[i]);
		}
	}
	return 0; 
}

HashTable CreatTable(int n)
{
	/*malloc����Ϊָ����ָ��ĵط������ڴ�ռ�*/
	HashTable H;
	int i;
	H=(HashTable)malloc(sizeof(struct HTable));
	H->size=NextPrime(n);
	H->list=(int*)malloc(H->size*sizeof(int));
	for(i=0;i<H->size;++i)
		H->list[i]=0;
	return H;
}
int Insert(HashTable H,int num)
{
	int pos,i;
	pos=num%H->size;
	/*���������̽�����*/
	for(i=0;i<=H->size/2&&H->list[pos];++i)
		pos=(pos+2*i+1)%H->size;
	if(i<=H->size/2){
		H->list[pos]=1;
		return pos;
	}	
	else return -1;
} 
int NextPrime(int n)
{
	int i,j;
	if(n==1||n%2==0)
		n++;
	/*����nΪ3���ϵ�����*/
	for(i=n;;i+=2){
		/*�жϱ��������ź���С�ĵ����ܷ��������*/ 
		for(j=3;j*j<=i&&i%j;++j);
		if(j*j>i) break;
	}
	return i;
}
