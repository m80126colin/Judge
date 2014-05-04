#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string x,string y) {
	return x+y>y+x;
}

int main() {
	string s[101];
	int n,i;
	while (cin>>n) {
		for (i=1;i<=n;i++) cin>>s[i];
		sort(s+1,s+n+1,cmp);
		for (i=1;i<=n;i++) cout<<s[i];
		cout<<endl;
	}
}