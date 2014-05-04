#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int p[4001];

int main() {
	bool ox;
	int i,j,t,n;
	string s;
	stringstream ss;
	p[1]=2,p[0]=1;
	for (i=3;i<=33000;i++) {
		for (j=1;j<=p[0];j++) {
			if (!(i%p[j])) break;
		}
		if (j>p[0]) {
			p[0]++;
			p[p[0]]=i;
		}
	}
	while (getline(cin,s)&&s!="0") {
		ss.clear();
		ss.str(s);
		n=1;
		while (ss>>t>>i) {
			for (i;i;i--) n*=t;
		}
		for (n--,ox=0,i=p[0];n>p[i];i--) ;
		for (i;n!=1;i--) {
			int k=0;
			while (!(n%p[i])) {
				k++;
				n/=p[i];
			}
			if (k) {
				if (ox) cout<<" ";
				cout<<p[i]<<" "<<k;
				ox=1;
			}
		}
		cout<<endl;
	}
}