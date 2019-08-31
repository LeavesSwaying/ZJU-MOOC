#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode{
	int Data;
	Tree Left;
	Tree Right;
};

inline int max(int a,int b){
	return a>b?a:b;
}

inline int GetHeight(struct TreeNode* Tree){
	if(Tree){
		int L=GetHeight(Tree->Left);
		int R=GetHeight(Tree->Right);
		return max(L,R)+1;
	}
	return 0;
}

Tree LLRotation(struct TreeNode* A){
	Tree B=A->Left;
	A->Left=B->Right;
	B->Right=A;
	return B;
}
Tree RRRotation(struct TreeNode* A){
	Tree B=A->Right;
	A->Right=B->Left;
	B->Left=A;
	return B;
}
Tree LRRotation(struct TreeNode* A){
	Tree B=A->Left;
	Tree C=B->Right;
	B->Right=C->Left;
	C->Left=B;
	A->Left=C->Right;
	C->Right=A;
	return C;
}
Tree RLRotation(struct TreeNode* A){
	Tree B=A->Right;
	Tree C=B->Left;
	A->Right=C->Left;
	C->Left=A;
	B->Left=C->Right;
	C->Right=B;
	return C;
}


Tree Insert(struct TreeNode* Head,int X)
{
	if(!Head){
		Head=(Tree)malloc(sizeof(struct TreeNode));
		Head->Data=X;
		Head->Left=Head->Right=NULL;
	}
	else if(X>Head->Data){
		Head->Right=Insert(Head->Right,X);
		if(GetHeight(Head->Right)-GetHeight(Head->Left)==2)
			if(X>Head->Right->Data) Head=RRRotation(Head);
			else if(X<Head->Right->Data) Head=RLRotation(Head);
	} 
	else if(X<Head->Data){
		Head->Left=Insert(Head->Left,X);
		if(GetHeight(Head->Left)-GetHeight(Head->Right)==2)
			if(X>Head->Left->Data) Head=LRRotation(Head);
			else if(X<Head->Left->Data) Head=LLRotation(Head);
	} 
	return Head;
}

int main()
{
	int k,N;
	struct TreeNode* Head=NULL;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&k);
		Head=Insert(Head,k);
	}
	printf("%d",Head->Data);
} 
