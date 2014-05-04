/*
ID: m80126c2
PROG: barn1
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("barn1.in");
ofstream cout("barn1.out");

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	int i,m,s,c,a[201];
	cin>>m>>s>>c;
	for (i=1;i<=c;i++) cin>>a[i];
	if (m>=c) cout<<c<<endl;
	else {
		sort (a+1,a+c+1);
		a[0]=a[c]-a[1];
		for (i=2;i<=c;i++) a[i-1]=a[i]-a[i-1];
		sort(a+1,a+c,cmp);
		for (i=1;i<m;i++) a[0]-=a[i];
		cout<<a[0]+m<<endl;
	}
}