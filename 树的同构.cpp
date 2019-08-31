#include<cstdio>

struct Tree {
	char name;
	int left;
	int right;
}T1[10], T2[10];

int BuildTree(struct Tree T[]) {
	char c,l, r;
	int N;
	int root = -1;
	int set[10] = { 0x00 };
	scanf("%d", &N);
	//这里必须有getchar来拿走N后面的回车 
	c=getchar();
	if (N) {
		for (int i = 0; i<N; ++i) {
			scanf("%c %c %c\n", &T[i].name, &l, &r);
			if (l != '-') {
				T[i].left = l - '0';
				set[T[i].left] = 1;
			}
			else T[i].left = -1;
			if (r != '-') {
				T[i].right = r - '0';
				set[T[i].right] = 1;
			}
			else T[i].right = -1;
		}
		int count;
		for (count = 0; count<N; ++count)
			if (set[count] == 0) break;
		root = count;
	}
	return root;
}

int	IsameTree(int t1, int t2) {
	//本树两空
	if (t1 == -1 && t2 == -1) return 1;
	//本树单空
	if (t1 == -1 || t2 == -1) return 0;
	//本树不空但名字不同
	if (T1[t1].name != T2[t2].name) return 0;
	//左子树全空，比较右子树
	if (T1[t1].left == -1 && T2[t2].left == -1)
		return IsameTree(T1[t1].right, T2[t2].right);
	//左子树全在且相同，比较左左和右右
	if ((T1[t1].left != -1 && T2[t2].left != -1) && (T1[T1[t1].left].name == T2[T2[t2].left].name))
		return (IsameTree(T1[t1].left, T2[t2].left) && IsameTree(T1[t1].right, T2[t2].right));
	else
		//其他情况比较左右和右左
		return (IsameTree(T1[t1].left, T2[t2].right) && IsameTree(T1[t1].right, T2[t2].left));
}

int main() {
	int head1, head2;
	int result;
	head1 = BuildTree(T1);
	head2 = BuildTree(T2);
	result = IsameTree(head1, head2);
	if (result) printf("Yes");
	else printf("No");
}
