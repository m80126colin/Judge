#include <iostream>
#include <string>
using namespace std;

int main() {
	char n[129];
	bool b;
	int t,a;
	cin>>t;
	for (cin.ignore(1);t;t--) {
		b=true;
		a=0;
		while (cin.get(n[0])&&n[0]!='\n') {
			if ((n[0]=='(')||(n[0]=='[')) n[++a]=n[0];
			if (((n[0]==')')&&(n[a]!='('))||((n[0]==']')&&(n[a]!='['))) b=false;
			if (((n[0]==')')&&(n[a]=='('))||((n[0]==']')&&(n[a]=='['))) n[a--]=' ';
		}
		if (b&&(a==0)) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}