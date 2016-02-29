#include <iostream>
using namespace std;

int main() {
	int n,a,r,t;
	bool ox[20001];
	while (cin>>n&&n) {
		while (cin>>a&&a) {
			memset(ox,1,sizeof(ox));
			for (t=1;t<=n;t++) ox[t]=0;
			ox[a]=1;
			r=a;
			for (t=n-1;t;t--) {
				cin>>a;
				if (a>r||ox[a+1]) {
					ox[a]=1;
					r=a;
				}
				else {
					if (ox[0]) {
						ox[0]=0;
						cout<<"No\n";
						continue;
					}
				}
			}
			if (ox[0]) cout<<"Yes\n";
		}
		cout<<endl;
	}
}