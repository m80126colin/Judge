/*
ID: m80126c2
PROG: palsquare
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream cin("palsquare.in");
ofstream cout("palsquare.out");

int b,n;

string base(int x) {
	string s="";
	for (char ch;x;x/=b) {
		if (x%b<10) ch=x%b+'0';
		else ch=x%b-10+'A';
		s=ch+s;
	}
	return s;
}

bool palindromic(int x) {
	int i;
	string s=base(x);
	for (i=0;i<=s.size()/2;i++) {
		if (s[i]!=s[s.size()-1-i]) return 0;
	}
	return 1;
}

int main() {
	cin>>b;
	for (n=1;n<=300;n++) {
		if (palindromic(n*n)) cout<<base(n)<<" "<<base(n*n)<<endl;
	}
}