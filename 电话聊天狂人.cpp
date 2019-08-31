/*纯C的散列过于繁琐，这道题学一下unordered_map*/
#include<iostream>
#include<string>
#include<unordered_map> 
using namespace std;

int main()
{
	int N;
	cin>>N;
	unordered_map<string,int> mp;
	mp.reserve(N);
	char s[12];
	for(int i(0);i<2*N;++i){
		scanf("%s",s);
		++mp[s];
	}
	auto it=mp.cbegin();
	int num=1;
	string minStr=it->first;
	int callCnt=it->second;
	for(++it;it!=mp.cend();++it)
		if(it->second==callCnt){
			++num;
			if(it->first<minStr) minStr=it->first;
		}
		else if(it->second>callCnt){
			num=1;
			minStr=it->first;
			callCnt=it->second;
		}
	cout<<minStr<<" "<<callCnt;
	if(num>1) cout<<" "<<num;
	return 0;
}
