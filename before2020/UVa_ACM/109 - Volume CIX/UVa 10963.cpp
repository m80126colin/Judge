#include <iostream>
using namespace std;

int main() {
	bool ox;
	int n,w,i,j,gap,a,b;
	for (cin>>n,i=1;i<=n;i++) {
		ox=1;
		for (cin>>w,j=1;j<=w;j++) {
			cin>>a>>b;
			if (j>1) {
				if (gap!=abs(a-b)) ox=0;
			}
			else gap=abs(a-b);
		}
		if (i>1) cout<<endl;
		if (ox) cout<<"yes\n";
		else cout<<"no\n";
	}
}