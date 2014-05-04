#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct edge{
	int x,y;
	bool ox;
}e[2000];
int node[2001],k;
vector <string> v;

int find_string(string x) {
	int i,j=-1;
	for (i=0;i<v.size();i++) {
		if (v[i]==x) j=i;
	}
	return j;
}

int dfs(int x,int y) {
	int maxn=y,i;
	for (i=0;i<k;i++) {
		if (e[i].x==x&&e[i].ox) e[i].ox=0,maxn=max(maxn,dfs(e[i].y,y+1));
		if (e[i].y==x&&e[i].ox) e[i].ox=0,maxn=max(maxn,dfs(e[i].x,y+1));
	}
	return maxn;
}

int main() {
	int n,r,i,j,maxn;
	string s,t;
	for (cin>>r;r;r--) {
		cin>>n;
		v.clear();
		memset(node,0,sizeof(node)),k=0;
		while (cin>>s>>t,s!="="||t!="=") {
			i=find_string(s);
			if (i==-1) v.push_back(s),i=v.size()-1;
			j=find_string(t);
			if (j==-1) v.push_back(t),j=v.size()-1;
			e[k].x=i,e[k].y=j,node[i]++,node[j]++,k++;
		}
		for (maxn=i=0;i<n;i++) {
			if (node[i]==1) {
				for (j=0;j<k;j++) e[j].ox=1;
				maxn=max(maxn,dfs(i,0));
			}
		}
		cout<<maxn<<endl;
	}
}