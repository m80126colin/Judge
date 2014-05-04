#include <iostream>
#include <string>
using namespace std;

struct ss{
	string s;
	int it;
};

bool cmp(ss a,ss b) {
	int i;
	if (a.it!=b.it) return a.it>b.it ;
	else {
		for (i=0;i<a.it;i++) if (a.s[i]!=b.s[i]) return a.s[i]>b.s[i];
		for (i=a.it+1;i<min(a.s.size(),b.s.size());i++) if (a.s[i]!=b.s[i]) return a.s[i]>b.s[i];
	}
	return a.s.size()>b.s.size();
}

int main() {
	int i;
	ss a,b;
	while (cin>>a.s>>b.s) {
		for (i=0;i<a.s.size();i++) if (a.s[i]=='.') break;
		a.it=i;
		for (i=0;i<b.s.size();i++) if (b.s[i]=='.') break;
		b.it=i;
		cout<<((cmp(a,b)) ? a.s : b.s)<<endl;
	}
}