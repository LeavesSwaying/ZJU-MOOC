/*排序上，各类排序算法的实现*/ 
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int data[100000],N;

void BubbleSort(int A[],int n)
{
	int p,temp,flag;
	for(p=n-1;p>0;--p){
		flag=0;
		for(int i=0;i<p;++i){
			if(A[i]>A[i+1]){
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
				flag=1;
			}
		}
		if(!flag) break;
	}
}
void InsertionSort(int A[],int n)
{
	int i,p,temp;
	for(p=1;p<n;++p){
		temp=A[p];
		for(i=p;i>=1&&A[i-1]>temp;i--)
			A[i]=A[i-1];
		A[i]=temp;
	}
}
void SelectSort(int A[],int N)
{
    int i,j,k,temp;
	for(i=0;i<N;++i){
		k=i;
		for(j=i+1;j<N;++j)
			if(A[k]>A[j])
				k=j;
		temp=A[i];
        A[i]=A[k];
        A[k]=temp;
	}
}

void ShellSort(int A[],int n)
{
	int i,D,P,Tmp;
	for(D=n/2;D>0;D/=2){
		for(P=D;P<n;P++){
			Tmp=A[P];
			for(i=P;i>=D&&A[i-1]>Tmp;i-=D)
				A[i]=A[i-D];
			A[i]=Tmp;
		}
	}
}
void SedgeSort(int A[],int N)
{
	int i,j,d,temp,Si;
	int Sedgewick[]={929,505,209,109,41,19,5,1,0};
	for(Si=0;Sedgewick[Si]>=N;Si++);
	for(d=Sedgewick[Si];d>0;d=Sedgewick[++Si]){
		for(i=d;i<N;++i){
			temp=A[i];
			for(j=i;j>=d&&A[j-d]>temp;j-=d)
				A[j]=A[j-d];
			A[j]=temp;
		}
	}
}
void PercDown(int A[],int N,int p)
{
	/*将N个元素的数组中以A[p]为根的子堆调整为最大堆*/
	int Parent,Child;
	int x;
	x=A[p];
	for(Parent=p;Parent*2+1<N;Parent=Child){
		Child=Parent*2+1;
		if((Child!=N-1)&&(A[Child]<A[Child+1]))
			Child++;
		if(x>=A[Child]) break;
		else A[Parent]=A[Child];
	}
	A[Parent]=x;
}
void HeapSort(int A[],int N)
{
	int i,temp;
	for(i=N/2;i>=0;i--)
		PercDown(A,N,i);
	for(i=N-1;i>0;i--){
		temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		PercDown(A,i,0);
	}
}
void Merge(int A[],int TmpA[],int L,int R,int RightEnd)
{
	int i,Tmp,LeftEnd,Num;
	LeftEnd=R-1;
	Tmp=L;
	Num=RightEnd-L+1;
	while(L<=LeftEnd&&R<=RightEnd){
		if(A[L]<=A[R]) TmpA[Tmp++]=A[L++];
		else TmpA[Tmp++]=A[R++];
	}
	while(L<=LeftEnd) TmpA[Tmp++]=A[L++];
	while(R<=RightEnd) TmpA[Tmp++]=A[R++];

	/*for(i=0;i<Num;i++,RightEnd--)
		A[RightEnd]=TmpA[RightEnd];*/
}
void MSort(int A[],int TmpA[],int L,int RightEnd)
{
	int Center;
	if(L<RightEnd){
		Center=(L+RightEnd)/2;
		MSort(A,TmpA,L,Center);
		MSort(A,TmpA,Center+1,RightEnd);
		Merge(A,TmpA,L,Center+1,RightEnd);
	}
}
void MergeSort(int A[],int N)
{
	int *TmpA;
	TmpA=(int*)malloc(N*sizeof(int));
	if(TmpA!=NULL){
		MSort(A,TmpA,0,N-1);
		free(TmpA);
	}
	else printf("空间不足");
}
void MergePass(int A[],int TmpA[],int N,int length)
{
	int i,j;
	for(i=0;i<=N-2*length;i+=2*length)
		Merge(A,TmpA,i,i+length,i+2*length-1);
	if(i+length<N)
		Merge(A,TmpA,i,i+length,N-1);
	else
		for(j=i;j<N;j++) TmpA[j]=A[j];
}
void Merge2Sort(int A[],int N)
{
	int *TmpA;
	TmpA=(int*)malloc(sizeof(int));
	int length=1;
	if(TmpA!=NULL){
		while(length<N){
			MergePass(A,TmpA,N,length);
			length*=2;
			MergePass(TmpA,A,N,length);
			length*=2;
			/*
			MergePass(A,TmpA,N,length);
			for(int i=0;i<N;++i) A[i]=TmpA[i];
			*/
		}
		free(TmpA);
	}
	else printf("空间不足");
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&data[i]);
	}
	
    //sort(data,data+N);
    //BubbleSort(data,N); 
	//InsertionSort(data,N);
	//SelectSort(data,N);
    //ShellSort(data,N);
	//SedgeSort(data,N);
	//HeapSort(data,N);
	Merge2Sort(data,N);

	for(int i=0;i<N;++i){
		if(i) printf(" ");
		printf("%d",data[i]);
	}
 } 
