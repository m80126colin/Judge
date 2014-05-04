/*
ID: m80126c2
PROG: dualpal
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream cin("dualpal.in");
ofstream cout("dualpal.out");

int b;

string base(int x) {
	string s="";
	for (char ch;x;x/=b) {
		ch=x%b+'0';
		s=ch+s;
	}
	return s;
}

bool palindromic(const int& x) {
	int i;
	string s=base(x);
	for (i=0;i<=s.size()/2;i++) {
		if (s[i]!=s[s.size()-1-i]) return 0;
	}
	return 1;
}

bool isdual(const int& x) {
	int t;
	t=0;
	for (b=2;b<=10;b++) {
		if (palindromic(x)) t++;
		if (t>=2) return 1;
	}
	return 0;
}

int main() {
	int t,n;
	for (cin>>t>>n,n++;t;n++) {
		if (isdual(n)) cout<<n<<endl,t--;
	}
}