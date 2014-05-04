#include <iostream>
#include <string>
using namespace std;

int main() {
	int t,i,j,m[10];
	string s,k;
	for (cin>>t,cin.ignore(1);t;t--) {
		s="0000000000";
		for (getline(cin,k),i=0;i<k.size();i++) {
			if (k[i]=='c') s+="0111001111";
			else if (k[i]=='d') s+="0111001110";
			else if (k[i]=='e') s+="0111001100";
			else if (k[i]=='f') s+="0111001000";
			else if (k[i]=='g') s+="0111000000";
			else if (k[i]=='a') s+="0110000000";
			else if (k[i]=='b') s+="0100000000";
			else if (k[i]=='C') s+="0010000000";
			else if (k[i]=='D') s+="1111001110";
			else if (k[i]=='E') s+="1111001100";
			else if (k[i]=='F') s+="1111001000";
			else if (k[i]=='G') s+="1111000000";
			else if (k[i]=='A') s+="1110000000";
			else s+="1100000000";
		}
		for (i=0;i<10;i++) {
			m[i]=0;
			for (j=i;j<s.size()-10;j+=10) {
				if (s[j]=='0'&&s[j+10]=='1') m[i]++;
			}
		}
		cout<<m[0];
		for (i=1;i<10;i++) cout<<" "<<m[i];
		cout<<endl;
	}
}