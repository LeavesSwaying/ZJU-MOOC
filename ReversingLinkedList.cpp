#include<iostream>
#include<string>
using namespace std;
class linked{
	public:
		int data;
		int next;
};
linked *list=new linked[100000];
int prehead;
int nexthead;
int Reverse(int head,int k){
	int cnt=1,temp;
	int news=head;
	int olds=list[head].next;
	while(cnt<k){
		temp=list[olds].next;
		list[olds].next=news;
		news=olds;
		olds=temp;
		cnt++;
	}
	list[head].next=olds;
	prehead=head;
	nexthead=olds;
	return news;
}
int main(){
	int firstNode,address,next,N,k,data,head,preshead;
	int sum=0;
	cin>>firstNode>>N>>k;
	for(int i=0;i<N;++i){
		cin>>address>>data>>next;
		list[address].data=data;
		list[address].next=next;
	}
	int p=firstNode;
	while(p!=-1){
		sum++;
		p=list[p].next;
	}
	head=Reverse(firstNode,k);
	for(int i=1;i<sum/k;++i){
		preshead=prehead;
		list[preshead].next=Reverse(nexthead,k);
	}
	p=head;
	while (p!= -1){
        printf("%05d ",p);
        cout << list[p].data <<" ";
        if (list[p].next != -1)
            printf("%05d\n", list[p].next);
        else
            cout << list[p].next << endl;
        p = list[p].next;
    }

	return 0;	
}
