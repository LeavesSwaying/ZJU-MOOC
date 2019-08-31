/*������ù����������Ҳ�����ʵĸо�*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int E,N;
int visited[200];
int path[200]={-1}; //������һ���ڵ�
struct crocodile
{
    int x;   //x����
    int y;  //y����
    int d;   //��0,0�����ƽ��
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
int calDist(crocodile a,crocodile b){   //��������֮��ľ���
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
    cin>>N>>E;
    for(int i=0;i<=N-1;i++){
        cin>>croco[i].x>>croco[i].y;
        croco[i].d=croco[i].x*croco[i].x+croco[i].y*croco[i].y; //������0��0�ľ���
    }
    qsort(croco,N,sizeof(croco[0]),cmp);      //���վ�����һ����
    if(E>=42.5){
        printf("1\n"); //һ���������������һ��û�����㣬����û������
        return 0;
    }
    else{         //����Ҫ��������
        queue <int> q;           //bfs�ر��Ķ��� 
        int last;
        for(int i=0;i<=N-1;i++){
            init();
            if(reachFromCenter(croco[i])){  //���е�һ�������Ľ���
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
                    s.push(element);   //�����һ�����㵽��һ���㿪ʼѹջ
                    element=path[element];   //��һ������
                }
                while(!s.empty()){
                    element=s.top();     //��ջ
                    s.pop();
                    printf("%d %d\n",croco[element].x, croco[element].y);
                }
                return 0;   //ֱ������
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
        if(q.empty()){  //�������������㻹������ֻ�����ڵ���
            printf("0\n");
        }
    }
    return 0;
}

