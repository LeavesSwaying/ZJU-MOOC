/*参考网上答案*/
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int MAX = 1e5 + 10;
int size = 0;
int heap[MAX];

void insert(int data){
    int i;
	for( i = ++size; data < heap[i/2]; i /= 2) heap[i] = heap[i/2];
    heap[i] = data;
}

int Delete(void){
    int temp = heap[1], i;
    int last = heap[size];
	heap[size--] = 0;
    for(i = 2; i <= size; i *= 2){
        if(heap[i] > heap[i+1] && i + 1 <= size) i++;
        if(heap[i] < last) heap[i/2] = heap[i];
		else break;
    }
    heap[i/2] = last;
    return temp;
}


int isPrefix(char *s1, char *s2) {		  
	while (s1 && s2 && *s1 == *s2)		 
		++s1, ++s2;
	if (*s1 == '\0' || *s2 == '\0')	 
		return 1;
	else
		return 0;
}

int hasPrefixCode(char s[][200], int n) { 
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (isPrefix(s[i], s[j]))						//s[i], s[j]都是字符串
				return 1;
	return 0;
}

int main() {
    int num, Wpl = 0;
    heap[0] = -1;
    cin >> num;
    map<char, int> m;
    for(int i = 0; i < num; i++){
        int temp;
        char name;
        cin >> name >> temp;
        m[name] = temp;
        insert(temp);
    }
	int heapsize = size;
    for(int i = 1; i < heapsize; i++){
        int temp1, temp2;
        temp1 = Delete();
        temp2 = Delete();
        insert(temp1 + temp2);
        Wpl  +=  temp1 + temp2;          					 //666
    }
    int checknum;
    cin >> checknum;
    while(checknum--){
        char ch[256];
		char s[256][200];
		int thisWPL = 0;
		for (int i = 0; i < num; ++i) {
			scanf("\n%c %s", &ch[i], s[i]);
			thisWPL += m[ch[i]] * strlen(s[i]);		 
		}
		if (thisWPL == Wpl && !hasPrefixCode(s, num))		 
			printf("Yes\n");
		else
			printf("No\n");
    }
	return 0;
}

