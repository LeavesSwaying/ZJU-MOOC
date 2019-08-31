#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 10010
struct Node{
    int x, y;
    int tag;
};

int N, D;// NΪ��������D Ϊ007��������Զ����
Node node[MAXN];    //û�ȹ� 0�� �ȹ�Ϊ1
bool flag = false;

double howDistance(int i , int j){
    double distance = sqrt(pow(node[i].x - node[j].x, 2)
                           + pow(node[i].y - node[j].y , 2));
    return distance;
}

bool isBorder(int i){
    int distance1 = abs(node[i].x) + D;
    int distance2 = abs(node[i].y) + D;
    if(distance1 >= 50 || distance2 >= 50){
        return true;
    }
    return false;
}

void dfs(int i){
    if(flag) return ;
    if(isBorder(i)){
        printf("Yes");
        flag = true;
        return ;
    }
    for(int j = 1; j <= N; ++j){
        if(node[j].tag == 0 && howDistance(j, i) <= D){
            node[j].tag = 1;
            dfs(j);
        }
    }
}

int main(void){
    scanf("%d%d", &N, &D);
    node[0].x = node[0].y = 0;
    node[0].tag = 1;    //  ����
    for(int i = 1; i <= N ; ++i){
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].tag = 0;
    }
    if(D + 15 >= 50){
        printf("Yes");
        return 0;
    }
    for(int i = 1 ; i <= N; ++i){
        if(flag) break;
        if(node[i].tag == 0 && 15 + D >= howDistance(i, 0)){
            node[i].tag = 1;
            dfs(i);
        }
    }
    if(!flag)
        printf("No");
    return 0;
}

