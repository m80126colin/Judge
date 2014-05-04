#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
	int t,i,j,x,y;
	while (cin>>a) {
		for (cin>>t;t;t--) {
			x=y=0;
			cin>>b;
			for (i=0;i<b.size();i++) {
				for (j=0;j<a.size();j++) {
					if (b[i]==a[j]) {
						if (i==j) x++;
						else y++;
						break;
					}
				}
			}
			cout<<x<<"A"<<y<<"B\n";
		}
	}
}