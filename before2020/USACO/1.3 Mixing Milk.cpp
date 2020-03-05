/*
ID: m80126c2
PROG: milk
LANG: C++
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("milk.in");
ofstream cout("milk.out");

struct milk {
	int p,q;
}m[5001];

istream& operator >> (istream& is,milk& x) {
	is>>x.p>>x.q;
	return is;
}

bool cmp(milk x,milk y) {
	return x.p<y.p;
}

int main() {
	int n,i,t,tol;
	cin>>n>>t;
	for (i=1;i<=t;i++) cin>>m[i];
	sort(m+1,m+t+1,cmp);
	for (tol=0,i=1;n;i++) {
		if (m[i].q<=n) {
			tol+=m[i].q*m[i].p;
			n-=m[i].q;
		}
		else {
			tol+=n*m[i].p;
			n=0;
		}
	}
	cout<<tol<<endl;
}