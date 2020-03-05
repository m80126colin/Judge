#include <iostream>
#include <vector>
using namespace std;

struct dot{
	int d[2];
}p[1000];

struct point{
	int x,t;
	bool ox[2];
}ree;

vector<point> v[1000];

void bfs(int a,int b,int c) {
	int i;
	if (p[a].d[b]>c) {
		for (i=0;i<v[a].size();i++) v[a][i].ox[b]=0;
	}
	p[a].d[b]=min(p[a].d[b],c);
	for (i=0;i<v[a].size();i++) {
		if (!v[a][i].ox[b]) {
			v[a][i].ox[b]=1;
			bfs(v[a][i].x,b,p[a].d[b]+v[a][i].t);
		}
	}
}

int main() {
	int n,m,i,j;
	while (scanf("%d %d",&n,&m),n||m) {
		for (i=0;i<n;i++) {
			p[i].d[0]=p[i].d[1]=2100000000;
			v[i].clear();
		}
		for (i=1;i<=m;i++) {
			cin>>j>>ree.x>>ree.t;
			ree.ox[0]=ree.ox[1]=0;
			v[j].push_back(ree);
		}
		cin>>i>>j;
		bfs(i,0,0);
		bfs(j,1,0);
		for (i=j=0;i<n;i++) {
			if (p[i].d[0]<p[i].d[1]) j++;
		}
		cout<<j<<endl;
	}
}