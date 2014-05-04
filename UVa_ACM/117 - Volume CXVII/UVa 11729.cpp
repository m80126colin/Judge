#include <iostream>
#include <algorithm>
using namespace std;

struct soldier{
	int b,j;
}s[10001];

bool cmp(soldier x,soldier y) {
	return (x.j>y.j)||(x.j==y.j)*(x.b<y.b);
}

int main() {
	int t,n,i,sum;
	for (t=1;cin>>n,n;t++) {
		for (i=1;i<=n;i++) cin>>s[i].b>>s[i].j;
		sort(s+1,s+n+1,cmp);
		for (sum=s[1].b+s[1].j,i=2;i<=n;i++) {
			s[i].b+=s[i-1].b;
			sum=max(sum,s[i].b+s[i].j);
		}
		cout<<"Case "<<t<<": "<<sum<<endl;
	}
}