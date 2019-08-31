#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

typedef struct Tree {
	int name;
	struct Tree *left;
	struct Tree *right;
}Tree;

Tree* BuildTree(int pre[], int in[], int ps, int is, int length) {
	if (!length) return 0;
	Tree *head;
	head = (Tree*)malloc(sizeof(Tree));
	head->name = pre[ps];
	if (length == 1) {
		head->left = 0;
		head->right = 0;
		return head;
	}
	int L = 0;
	while (in[is + L] != pre[ps]) L++;
	head->left = BuildTree(pre, in,ps+1,is,L);
	head->right = BuildTree(pre, in,ps+L+1,is+L+1,length-L-1);
	return head;
}

void PostTravel(Tree *T) {
    static int c=0;
	if (T != 0) {
		PostTravel(T->left);
		PostTravel(T->right);
        if(c++) cout<<' ';
		cout<<T->name;
	}
}

int main() {
	//初始化读入数据，并抽取先序和中序遍历结果 
	int N;
	cin >> N;
	int stack[30], preord[30], inord[30];
	int s_head, p_head, i_head;
	s_head = -1; p_head = 0; i_head = 0;
	string str;
	int temp;
	for (int i = 0; i<2 * N; ++i) {
		cin >> str;
		if (str == "Push") {
			cin >> temp;
			stack[++s_head] = temp;
			preord[p_head++] = temp;
		}
		else {
			temp = stack[s_head--];
			inord[i_head++] = temp;
		}
	}
	//我们得到了两个数组，存放先序和中序遍历序列
	Tree *T;
	T = BuildTree(preord, inord, 0,0,N);
	//接着后序遍历输出 
	PostTravel(T);
	return 0;
}
