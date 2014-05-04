#include <iostream>
#include <string>
#include <map>
using namespace std;

int n,m,a[6];
map <string,int> mm;
struct pair{
	int first,second;
}v[30];

bool dfs(int x) {
	bool ox1=0,ox2=0,ox=0;
	if (x==m) return 1;
	if (!(a[v[x].first]+1>n)) {
		ox1=1;
		a[v[x].first]++;
		if (dfs(x+1)) ox=1;
	}
	if (ox1) a[v[x].first]--;
	if (!(a[v[x].second]+1>n)) {
		ox2=1;
		a[v[x].second]++;
		if (dfs(x+1)) ox=1;
	}
	if (ox2) a[v[x].second]--;
	return ox;
}

int main() {
	string t1,t2,s[6]={"XXL","XL","L","M","S","XS"};
	int i;
	for (i=0;i<6;i++) mm[s[i]]=i;
	while (cin>>n>>m) {
		n/=6;
		for (i=0;i<m;i++) {
			cin>>t1>>t2;
			v[i].first=mm[t1],v[i].second=mm[t2];
		}
		memset(a,0,sizeof(a));
		if (dfs(0)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}