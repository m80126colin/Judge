#include <iostream>
#include <vector>
using namespace std;

struct edge{
	int x,y;
	bool ox;
}v[10000];
int n,k,node[10001];

int dfs(int x,int y) {
	int maxn=y,i;
	for (i=0;i<k;i++) {
		if (v[i].x==x&&v[i].ox) v[i].ox=0,maxn=max(maxn,dfs(v[i].y,y+1));
		if (v[i].y==x&&v[i].ox) v[i].ox=0,maxn=max(maxn,dfs(v[i].x,y+1));
	}
	return maxn;
}

int main() {
	int i,j,maxn;
	while (cin>>n) {
		memset(node,0,sizeof(node));
		for (k=i=0;i<n;i++) {
			while (cin>>j,j!=-1) v[k].x=i,v[k].y=j,node[i]++,k++;
		}
		for (maxn=i=0;i<n;i++) {
			if (!node[i]) {
				for (j=0;j<n;j++) v[j].ox=1;
				maxn=max(maxn,dfs(i,0));
			}
		}
		cout<<maxn<<endl;
	}
}