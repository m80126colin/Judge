#include <iostream>
#include <string>
using namespace std;

int main() {
	string s,s1,s2;
	int k,n,i,t;
	for (cin>>k;k;k--) {
		i=2100000000,s="";
		for (cin>>n;n;n--) {
			cin>>s1>>s2>>t;
			s1+=" "+s2;
			if (t<i) {
				i=t;
				s=s1;
			}
		}
		if (i<0) cout<<s<<endl;
		else cout<<"Are you kidding me?"<<endl;
	}
}