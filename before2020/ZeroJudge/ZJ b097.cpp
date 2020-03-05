#include <iostream>
using namespace std;

int re(int x,int y,int &z) {
	if (x%y) re(y,x%y,z);
	else z=y;
	return 0;
}

int main() {
	int m,n,s,t;
	for (cin>>t;t;t--) {
		cin>>m>>n;
		re(max(m,n),min(m,n),s);
		cout<<m*n/s<<endl;
	}
}