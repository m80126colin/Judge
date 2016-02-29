#include <iostream>
#include <algorithm>
using namespace std;

struct num{
	int a,b,c;
}s[1001];

bool cmp(num x,num y) {
	return (x.c>y.c)+(x.c==y.c)*(x.a>y.a);
}

int main() {
	int n,i;
	while (cin>>n,n) {
		for (i=1;i<=n;i++) cin>>s[i].a>>s[i].b,s[i].c=s[i].a+s[i].b;
		sort(s+1,s+n+1,cmp);
		for (i=1;i<=n;i++) {
			if (i>1) cout<<" ";
			if (s[i].a>s[i].b) cout<<">";
			else if (s[i].a<s[i].b) cout<<"<";
			else cout<<"=";
			cout<<s[i].c;
		}
		cout<<endl;

	}
}