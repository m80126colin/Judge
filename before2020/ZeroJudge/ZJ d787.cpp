#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,carry,i,ox;
	string a,b;
	for (cin>>n;n;n--) {
		cin>>a>>b;
		carry=ox=0;
		if (a.size()<b.size()) swap(a,b);
		for (i=1;i<=b.size();i++) {
			if (a[a.size()-i]+b[b.size()-i]-'0'-'0'+ox >= 10) carry++,ox=1;
			else ox=0;
		}
		while (ox&&i<=a.size()) {
			if (a[a.size()-i]-'0'+ox >= 10) carry++,ox=1;
			else ox=0;
			i++;
		}
		cout<<carry<<endl;
	}
}