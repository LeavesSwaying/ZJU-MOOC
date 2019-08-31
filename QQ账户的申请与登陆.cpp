#include<iostream>
#include<map> 
using namespace std;

map<string,string> mp;

int main()
{
	int N;
	cin>>N;
	char a1;string a2,a3;
	while(N--)
	{
		cin>>a1>>a2>>a3;
		if(a1=='N')
			if(mp.find(a2)==mp.end()){
				mp[a2]=a3;
				cout<<"New: OK\n";
			}
			else
				cout<<"ERROR: Exist\n";
		if(a1=='L')
			if(mp.find(a2)==mp.end())
				cout<<"ERROR: Not Exist\n";
			else{
				map<string,string>::iterator it;
				it=mp.find(a2);
				if(it->second==a3)
					cout<<"Login: OK\n";
				else
					cout<<"ERROR: Wrong PW\n";
			}
	}
	return 0;	
} 
