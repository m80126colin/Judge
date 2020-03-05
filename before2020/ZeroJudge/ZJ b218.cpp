#include <iostream>
#include <vector>
using namespace std;

struct edge{
	int x,y;
	bool ox;
}e[20000];
int n,node[20001];

int dfs(int x) {
	int i,j,sum;
	vector<int> v;
	for (i=1;i<n;i++) {
		if (e[i].x==x&&!e[i].ox) {
			e[i].ox=1;
			j=dfs(e[i].y);
			v.push_back(j);
		}
		if (e[i].y==x&&!e[i].ox) {
			e[i].ox=1;
			j=dfs(e[i].x);
			v.push_back(j);
		}
	}
	if (v.empty()) sum=0;
	else {
		for (sum=n,i=0;i<v.size();i++) sum-=v[i];
		sum--;
		v.push_back(sum);
	}
	for (sum=i=0;i+1<v.size();i++) sum+=v[i];
	for (i=0;i<v.size();i++) {
		for (j=i+1;j<v.size();j++) node[x]+=v[i]*v[j];
	}
	return sum+1;
}

int main() {
	int i,maxn=1,num=1;
	cin>>n;
	memset(e,0,sizeof(e));
	memset(node,0,sizeof(node));
	for (i=1;i<n;i++) cin>>e[i].x>>e[i].y;
	dfs(1);
	for (i=1;i<=n;i++) {
		if (node[i]>maxn) num=i,maxn=node[i];
	}
	cout<<num<<" "<<maxn<<endl;
}