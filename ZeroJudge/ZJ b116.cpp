#include <iostream>
using namespace std;

int main() {
	static bool a[100001];
	int n,m,b,i,j,t;
	while (cin>>m>>n) {
		for (m;m;m--) {
			memset(a,0,sizeof(a));
			b=0;
			for (i=1,a[0]=1;i<=n;i++) {
				cin>>t;
				for (j=100000;j>=0;j--) {
					if (a[j]) a[j+t]=1;	
				}
				b+=t;
			}
			if (b%2) cout<<"No"<<endl;
			else if (a[b/2]) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}