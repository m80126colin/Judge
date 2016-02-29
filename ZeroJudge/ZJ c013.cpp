#include <iostream>
using namespace std;

int main() {
	int n,a,f,i,j,k;
	for (cin>>n;n;n--) {
		cin>>a>>f;
		for (i=1;i<=f;i++) {
			for (j=1;j<=a;j++) {
				for (k=1;k<=j;k++) cout<<j;
				cout<<endl;
			}
			for (j=a-1;j;j--) {
				for (k=1;k<=j;k++) cout<<j;
				cout<<endl;
			}
			if (i!=f) cout<<endl;
		}
		if (n!=1) cout<<endl;
	}
}