#include <iostream>
using namespace std;

int main() {
	int m,n,a,b;
	long long s;
	while (cin>>n>>m&&(n||m)) {
		s=1;
		b=min(n-m,m);
		for (a=max(n-m,m);n>a;n--) {
			s*=n;
			if (s%b==0&&b) {
				s/=b;
				b--;
			}
		}
		for (b;b;b--) s/=b;
		cout<<s<<endl;
	}
}