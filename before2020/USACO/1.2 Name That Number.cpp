/*
ID: m80126c2
PROG: namenum
LANG: C++
*/
#include <fstream>
#include <string>
#include <map>
using namespace std;

ifstream cin("dict.txt");
ofstream cout("namenum.out");

map<string,string> m;

string convert(const string& x) {
	int i;
	string s="";
	for (i=0;i<x.size();i++) {
		if (x[i]=='A'||x[i]=='B'||x[i]=='C') s+="2";
		else if (x[i]=='D'||x[i]=='E'||x[i]=='F') s+="3";
		else if (x[i]=='G'||x[i]=='H'||x[i]=='I') s+="4";
		else if (x[i]=='J'||x[i]=='K'||x[i]=='L') s+="5";
		else if (x[i]=='M'||x[i]=='N'||x[i]=='O') s+="6";
		else if (x[i]=='P'||x[i]=='R'||x[i]=='S') s+="7";
		else if (x[i]=='T'||x[i]=='U'||x[i]=='V') s+="8";
		else if (x[i]=='W'||x[i]=='X'||x[i]=='Y') s+="9";
	}
	return s;
}

int main() {
	string s,t;
	while (cin>>s) {
		t=convert(s);
		m[t]+=s+"\n";
	}
	cin.close();
	ifstream cin("namenum.in");
	cin>>t;
	if (m[t]=="") cout<<"NONE\n";
	else cout<<m[t];
}