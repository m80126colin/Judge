/*
ID: m80126c2
PROG: crypt1
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream cin("crypt1.in");
ofstream cout("crypt1.out");

int t,a[10],j[5];

int isright() {
	int i,k;
	bool ox;
	i=a[j[4]]*(a[j[0]]*100+a[j[1]]*10+a[j[2]]);
	if (i/1000) return 0;
	while (i) {
		ox=0;
		for (k=1;k<=t;k++) {
			if (a[k]==i%10) ox=1;
		}
		if (!ox) return 0;
		i/=10;
	}
	i=a[j[3]]*(a[j[0]]*100+a[j[1]]*10+a[j[2]]);
	if (i/1000) return 0;
	while (i) {
		ox=0;
		for (k=1;k<=t;k++) {
			if (a[k]==i%10) ox=1;
		}
		if (!ox) return 0;
		i/=10;
	}
	i=(a[j[3]]*10+a[j[4]])*(a[j[0]]*100+a[j[1]]*10+a[j[2]]);
	if (i/10000) return 0;
	while (i) {
		ox=0;
		for (k=1;k<=t;k++) {
			if (a[k]==i%10) ox=1;
		}
		if (!ox) return 0;
		i/=10;
	}
	return 1;
}

int main() {
	int i,tol;
	cin>>t;
	tol=0;
	for (i=1;i<=t;i++) cin>>a[i];
	for (j[0]=1;j[0]<=t;j[0]++) {
		for (j[1]=1;j[1]<=t;j[1]++) {
			for (j[2]=1;j[2]<=t;j[2]++) {
				for (j[3]=1;j[3]<=t;j[3]++) {
					for (j[4]=1;j[4]<=t;j[4]++) tol+=isright();
				}
			}
		}
	}
	cout<<tol<<endl;
}