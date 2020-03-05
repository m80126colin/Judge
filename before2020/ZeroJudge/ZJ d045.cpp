#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int t1,t,i,j,s[4][10001];
	stringstream ss;
	string n[4];
	for (cin>>t1,t=1;t<=t1;t++) {
		for (i=3;i;i--) {
			n[i]="";
			for (j=10000;j;j--) {
				s[i][j]=0;
			}
		}
		for (i=1;i<=3;i++) {
			cin>>s[i][0];
			for (j=1;j<=s[i][0];j++) {
				cin>>s[0][0];
				s[i][s[0][0]]++;
			}
		}
		for (i=1,s[1][0]=s[2][0]=s[3][0]=0;i<=10000;i++) {
			ss.str("");
			if (s[1][i]&&s[2][i]==0&&s[3][i]==0) {
				s[1][0]++;
				ss<<i;
				n[0]=ss.str();
				n[1]+=" "+n[0];
			}
			if (s[2][i]&&s[1][i]==0&&s[3][i]==0) {
				s[2][0]++;
				ss<<i;
				n[0]=ss.str();
				n[2]+=" "+n[0];
			}
			if (s[3][i]&&s[1][i]==0&&s[2][i]==0) {
				s[3][0]++;
				ss<<i;
				n[0]=ss.str();
				n[3]+=" "+n[0];
			}
		}
		j=max(max(s[1][0],s[2][0]),s[3][0]);
		cout<<"Case #"<<t<<":"<<endl;
		for (i=1;i<=3;i++) {
			if (j==s[i][0]) {
				cout<<i<<" "<<s[i][0]<<n[i]<<endl;
			}
		}
	}
}