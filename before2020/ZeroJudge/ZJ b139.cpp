#include <iostream>
using namespace std;

int main() {
	int m,n,a,b;
	bool l[10001];
	while (cin>>n) {
		memset(l,1,sizeof(l));
		for (cin>>m;m;m--) {
			for (cin>>a>>b;a<=b;a++) l[a]=0;
		}
		for (m=0,a=0;a<=n;a++) {
			if (l[a]) m++;
		}
		cout<<m<<endl;
	}
}