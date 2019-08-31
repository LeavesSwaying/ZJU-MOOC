/*这道题用广度优先搜索也蛮合适的感觉*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int E,N;
int visited[200];
int path[200]={-1}; //保存上一个节点
struct crocodile
{
    int x;   //x坐标
    int y;  //y坐标
    int d;   //与0,0距离的平方
}croco[200];
int reachFromCenter(crocodile p){
    int a=(7.5+E)*(7.5+E);
    if(p.d<=a) return p.d;
    else return 0;
}
int cmp(const void *a,const void *b){
    return ((*(crocodile *)a).d)-((*(crocodile *)b).d);
}
int success(crocodile a){
    return a.x>=50-E||a.y>=50-E||a.x-E<=-50||a.y-E<=-50;
}
void init(){
    memset(visited,-1,sizeof(visited));
}
int calDist(crocodile a,crocodile b){   //计算两点之间的距离
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
    cin>>N>>E;
    for(int i=0;i<=N-1;i++){
        cin>>croco[i].x>>croco[i].y;
        croco[i].d=croco[i].x*croco[i].x+croco[i].y*croco[i].y; //计算与0，0的距离
    }
    qsort(croco,N,sizeof(croco[0]),cmp);      //按照距离排一次序
    if(E>=42.5){
        printf("1\n"); //一跳就能跳出，输出一，没踩鳄鱼，所有没有鳄鱼
        return 0;
    }
    else{         //必须要踩鳄鱼了
        queue <int> q;           //bfs必备的队列 
        int last;
        for(int i=0;i<=N-1;i++){
            init();
            if(reachFromCenter(croco[i])){  //所有第一步能跳的进队
                q.push(i);
                visited[i]=0;
                last=i;
            }
        }
        int step=2;
        int tail;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            if(success(croco[element])){
                int k=1;
                stack <int> s;
                printf("%d\n",step);
                while(k<step){
                    k++;
                    s.push(element);   //从最后一条鳄鱼到第一条鱼开始压栈
                    element=path[element];   //上一条鳄鱼
                }
                while(!s.empty()){
                    element=s.top();     //出栈
                    s.pop();
                    printf("%d %d\n",croco[element].x, croco[element].y);
                }
                return 0;   //直接跳出
            }
            for(int i=0;i<=N-1;i++){
                if(visited[i]==-1&&calDist(croco[element],croco[i])<=E*E){
                    q.push(i);
                    path[i]=element;
                    visited[i]=0;
                    tail=i;
                }
            }
            if(last==element){
                step++;
                last=tail;
            }
        }
        if(q.empty()){  //跳完了所有鳄鱼还跳不出只能死在岛上
            printf("0\n");
        }
    }
    return 0;
}

