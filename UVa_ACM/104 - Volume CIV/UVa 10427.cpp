#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int cmp[9],i,j,k,n;
	string s;
	stringstream ss;
	memset(cmp,0,sizeof(cmp));
	for (i=1,j=9;i<=8;i++,j*=10) {
		for (k=i;k<=8;k++) cmp[k]+=j*i;
	}
	while (cin>>n) {
		j=9;
		for (i=0;i<8;i++) {
			if (i>=2) j=j*10+9;
			if (n>cmp[i]&&n<=cmp[i+1]) break;
		}
		if (!i) j=0;
		n-=cmp[i]+1;
		k=n/(i+1)+j+1;
		ss.str("");
		ss<<k;
		s=ss.str();
		cout<<s[n%(i+1)]<<endl;
	}
}