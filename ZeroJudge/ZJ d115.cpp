#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int n[101],m;

int re(int x,int y,string z) {
	string s;
	stringstream ss;
	if (y) {
		for (;x<=n[0]+1-y;x++) {
			ss.clear();
			ss<<n[x];
			ss>>s;
			re(x+1,y-1,z+" "+s);
		}
	}
	else cout<<z.substr(1,z.size()-1)<<endl;
	return 0;
}

int main() {
	bool ox;
	int i;
	ox=0;
	while (cin>>n[0]&&n[0]) {
		for (i=1;i<=n[0];i++) cin>>n[i];
		cin>>m;
		sort(n+1,n+n[0]+1);
		if (ox) cout<<endl;
		re(1,m,"");
		ox=1;
	}
}