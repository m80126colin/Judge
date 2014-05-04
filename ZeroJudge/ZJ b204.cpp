#include <iostream>
using namespace std;

int main() {
	int n,t,x,y,i;
	while (cin>>n&&n) {
		t=0;
		for (i=1;i<=n;i++) {
			if (i==1) cin>>x;
			else {
				cin>>y;
				if (y-x>0) t+=(y-x)*20;
				else t+=(y-x)*(-10);
				x=y;
			}
		}
		cout<<t<<endl;
	}
}