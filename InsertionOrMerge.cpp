#include<iostream>
#include<cstdlib>
using namespace std;

int data1[100],data2[100],result[100],N;

bool Judge(int A[],int B[],int N){
	for(int i=0;i<N;++i)
		if(A[i]!=B[i]) return false;
	return true;
}

bool InsertSort(int A[],int N){
	int i,j,temp;
	for(i=1;i<N;++i){
		temp=A[i];
		for(j=i;j>=1&&A[j-1]>temp;--j){
			A[j]=A[j-1];
		}
		A[j]=temp;
		if(Judge(A,result,N)){
			temp=A[++i];
			for(j=i;j>=1&&A[j-1]>temp;--j)
				A[j]=A[j-1];
			A[j]=temp;
			return true;
		}
	}
	return false;
}

void Merge(int A[],int TmpA[],int L,int R,int RightEnd){
	int LeftEnd=R-1;
	int Num=RightEnd-L+1;
	int Tmp=L;
	while(L<=LeftEnd&&R<=RightEnd){
		if(A[L]<=A[R]) TmpA[Tmp++]=A[L++];
		else TmpA[Tmp++]=A[R++];
	}
	while(L<=LeftEnd) TmpA[Tmp++]=A[L++];
	while(R<=RightEnd) TmpA[Tmp++]=A[R++];
	for(int i=0;i<Num;++i,--RightEnd)
		A[RightEnd]=TmpA[RightEnd];
}

void MergePass(int A[],int TmpA[],int N,int length){
	int i,j;
	for(i=0;i<N-2*length;i+=2*length)
		Merge(A,TmpA,i,i+length,i+2*length-1);
	if(i+length<N)
		Merge(A,TmpA,i,i+length,N-1);
	else
		for(j=i;j<N;j++) TmpA[j]=A[j];
}

bool MergeSort(int A[],int N){
	int length;
	length=1;
	int *TmpA;
	TmpA=(int*)malloc(N*sizeof(int));
	if(TmpA!=NULL){
		while(length<N){
			MergePass(A,TmpA,N,length);
			length*=2;
			if(Judge(A,result,N)){
				MergePass(A,TmpA,N,length);
				return true;
			}
		}
		free(TmpA);
	}
	else printf("¿Õ¼ä²»×ã"); 
	return false;
}

void PrintArray(int A[],int N){
	for(int i=0;i<N;++i){
		if(i) cout<<' ';
		cout<<A[i];
	}
}
int main(){
	cin>>N;
	int temp;
	for(int i=0;i<N;++i){
		cin>>temp;
		data1[i]=data2[i]=temp;
	}
	for(int i=0;i<N;++i){
		cin>>result[i];
	}
	if(InsertSort(data1,N)){
		cout<<"Insertion Sort"<<endl;
		PrintArray(data1,N);
	}
	if(MergeSort(data2,N)){
		cout<<"Merge Sort"<<endl;
		PrintArray(data2,N);
	}
} 
