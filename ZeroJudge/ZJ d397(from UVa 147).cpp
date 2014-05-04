#include <iostream>
#include <string.h>
#include <iomanip>
#include <string>
using namespace std;

long long n[6001];

int re(int x) {
	int i;
	for (i=x;i<=6000;i++) if (i>=x) n[i]+=n[i-x];
	return 0;
}

int main() {
	int i,j;
	string a;
	memset(n,0,sizeof(n));
	n[0]=1;
	re(1);
	re(2);
	re(4);
	re(10);
	re(20);
	re(40);
	re(100);
	re(200);
	re(400);
	re(1000);
	re(2000);
	while (cin>>a&&a!="0.00") {
		for (i=j=0;i<a.size();i++) {
			if (a[i]>='0'&&a[i]<='9') {
				j+=a[i]-48;
				if (i<a.size()-1) j*=10;
			}
		}
		cout<<setw(6)<<a<<setw(17)<<n[j/5]<<endl;
	}
}