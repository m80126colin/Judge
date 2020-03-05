#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	int a[26],i,maxn,minn;
	string s;
	while (cin>>s) {
		memset(a,0,sizeof(a));
		for (i=0;i<s.size();i++) a[s[i]-97]++;
		for (i=maxn=minn=0;i<26;i++) {
			if (maxn&&minn) {
				if (a[i]>maxn) maxn=a[i];
				if (a[i]<minn&&a[i]) minn=a[i];
			}
			else maxn=minn=a[i];
		}
		ox=1;
		maxn-=minn;
		for (i=2;i*i<=maxn;i++) {
			if (!(maxn%i)) {
				ox=0;
				break;
			}
		}
		if (ox&&maxn>1) printf("Lucky Word\n%d\n",maxn);
		else printf("No Answer\n0\n");
	}
}