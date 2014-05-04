#include <iostream>
#include <string>
using namespace std;

struct edge{
	int first,second;
	bool ox;
}e[201],temp;

bool operator == (const edge& x,const edge& y) {
	return x.first==y.first&&x.second==y.second;
}

int k;
bool node[26];

void dfs(int x) {
	int i;
	node[x]=0;
	for (i=0;i<k;i++) {
		if (x==e[i].first&&e[i].ox) e[i].ox=0,dfs(e[i].second);
		if (x==e[i].second&&e[i].ox) e[i].ox=0,dfs(e[i].first);
	}
}

int main() {
	bool ox2;
	string s;
	int t,n,i,ctr;
	char ch;
	for (cin>>t;t;t--) {
		cin>>ch,cin.ignore(1),n=ch-'A';
		for (k=0;getline(cin,s)&&s!="";k++) {
			ox2=1;
			temp.first=min(s[0]-'A',s[1]-'A'),temp.second=max(s[0]-'A',s[1]-'A'),temp.ox=1;
			for (i=0;i<k;i++) if (temp==e[i]) ox2=0,k--;
			if (ox2) e[k]=temp;
		}
		memset(node,1,sizeof(node));
		for (i=ctr=0;i<=n;i++) if (node[i]) ctr++,dfs(i);
		cout<<ctr<<endl;
		if (t>1) cout<<endl;
	}
}