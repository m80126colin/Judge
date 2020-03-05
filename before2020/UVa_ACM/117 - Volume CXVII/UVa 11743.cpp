#include <iostream>
#include <string>
using namespace std;

int main() {
	char ch;
	int ctr,i,j,k;
	string s,t;
	for (cin>>ctr;ctr;ctr--) {
		s="";
		while (cin>>t,cin.get(ch)) {
			s+=t;
			if (ch=='\n') break;
		}
		for (i=j=0;i<s.size();i++) {
			k=s[i]-'0';
			if (!(i&1)) {
				k*=2;
				int tmp;
				for (tmp=0;k;k/=10) tmp+=k%10;
				k=tmp;
			}
			j+=k;
			
		}
		if (j%10) cout<<"Invalid\n";
		else cout<<"Valid\n";
	}
}