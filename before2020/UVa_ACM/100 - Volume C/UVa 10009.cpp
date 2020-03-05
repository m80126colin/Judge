#include <iostream>
#include <string>
#include <map>
using namespace std;

int flag;
string s,t;

bool find(char x) {
	int i;
	for (i=0;i<s.size();i++) {
		if (x==s[i]) {
			flag=i;
			return 1;
		}
	}
	return 0;
}

int main() {
	int ctr,n,m,i;
	char ch1,ch2;
	map<char,char> mm;
	for (cin>>ctr;ctr;ctr--) {
		mm.clear();
		mm['R']='R';
		for (cin>>n>>m,i=1;i<=n;i++) {
			cin>>s>>t;
			mm[t[0]]=s[0];
		}
		for (i=1;i<=m;i++) {
			cin>>s>>t;
			ch1=s[0],ch2=t[0];
			s=s.substr(0,1);
			while (mm[ch1]!=ch1) s+=mm[ch1],ch1=mm[ch1];
			t=t.substr(0,1);
			while (!find(t[0])) t=mm[ch2]+t,ch2=mm[ch2];
			cout<<s.substr(0,flag)<<t<<endl;
		}
		if (ctr>1) cout<<endl;
	}
}