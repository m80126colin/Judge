#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct poker{
	char kind;
	int num;
}c[53];
string s="SHDC";
map<char,int> m;

bool cmp(poker x,poker y) {
	return (x.num>y.num)||(x.num==y.num)*(m[x.kind]<m[y.kind]);
}

int main() {
	int n,i;
	for (i=0;i<s.size();i++) m[s[i]]=i;
	for (cin>>n,i=1;i<=n;i++) cin>>c[i].kind>>c[i].num;
	sort(c+1,c+n+1,cmp);
	cin>>i;
	cout<<c[i].kind<<" "<<c[i].num<<endl;
}