#include<cstdio>

struct Tree {
	int left;
	int right;
}T[10];

void TreeTravel(int head) {
	int q[20];
	int start = 0;
	int end = 0;
	if (head == -1) return;
	q[end++] = head;
	int temp;
    int num=0;
	while (start != end) {
		temp = q[start++];
		if (T[temp].left == -1 && T[temp].right == -1){
            if(num++) printf(" ");
            printf("%d", temp);
        } 
		if (T[temp].left != -1) q[end++] = T[temp].left;
		if (T[temp].right != -1) q[end++] = T[temp].right;
	}
}

int main() {
	//建树过程 
	int N;
	scanf("%d", &N);
	getchar();
	char left, right;
	int flag[10] = { 0 };
	for (int i = 0; i<N; ++i) {
		scanf("%c %c\n", &left, &right);
		if (left != '-') {
			T[i].left = left - '0';
			flag[T[i].left] = 1;
		}
		else T[i].left = -1;
		if (right != '-') {
			T[i].right = right - '0';
			flag[T[i].right] = 1;
		}
		else T[i].right = -1;
	}
	//寻找根 
	int k = -1;
	for (k = 0; k<N; ++k)
		if (flag[k] == 0) break;
	//遍历过程
	TreeTravel(k);
	return 0;
}
