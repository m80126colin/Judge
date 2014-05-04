#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int t,ctr,c,n;
	for (cin>>t,ctr=1;ctr<=t;ctr++) {
		s="";
		cin>>n;
		cout<<"Case #"<<ctr<<": ";
		for (c=0;n;n/=2,c++) {
			if (n&1) {
				s="1"+s;
				n+=(c&1)+((c&1)==0)*(-1);
			}
			else s="0"+s;
		}
		if (!s.size()) s="0";
		cout<<s<<endl;
	}
}