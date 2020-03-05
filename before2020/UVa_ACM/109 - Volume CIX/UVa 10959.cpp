#include <iostream>
#include <queue>
using namespace std;

struct ab {
	int a;
	int b;
	bool ox;
};

int main() {
	int t,i,j,p[1000],d,e;
	queue <int> q;
	static ab x[500000];
	for (cin>>t;t;t--) {
		cin>>i>>j;
		p[0]=0;
		for (d=1;d<i;d++) p[d]=99999;
		for (d=1;d<=j;d++) {
			cin>>x[d].a>>x[d].b;
			x[d].ox=1;
		}
		q.push(0);
		while (1) {
			e=q.front();
			for (d=1;d<=j;d++) {
				if (x[d].ox) {
					if (x[d].a==e) {
						q.push(x[d].b);
						p[x[d].b]=min(p[x[d].b],p[x[d].a]+1);
						x[d].ox=0;
					}
					if (x[d].b==e) {
						q.push(x[d].a);
						p[x[d].a]=min(p[x[d].a],p[x[d].b]+1);
						x[d].ox=0;
					}
				}
			}
			q.pop();
			if (q.empty()) break;
		}
		for (d=1;d<i;d++) cout<<p[d]<<endl;
		if (t!=1) cout<<endl;
	}
}