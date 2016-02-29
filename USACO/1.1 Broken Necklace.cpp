/*
ID: m80126c2
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

int main() {
	int n,m,i,j,k;
	char ch;
	string s;
	while (fin>>n>>s) {
		s+=s,m=0;
		for (i=0;i<s.size();i++) {
			k=0;
			if (i-1>=0) {
				ch=s[i-1];
				for (j=i-1;j>=0;j--) {
					if (ch!=s[j]) {
						if (ch=='w') ch=s[j];
						else {
							if (s[j]=='w') continue;
							break;
						}
					}
				}
				k+=i-j-1;
			}
			if (i<s.size()) {
				ch=s[i];
				for (j=i;j<s.size();j++) {
					if (ch!=s[j]) {
						if (ch=='w') ch=s[j];
						else {
							if (s[j]=='w') continue;
							break;
						}
					}
				}
				k+=j-i;
			}
			if (k>m) m=k;
		}
		if (m>n) m=n;
		fout<<m<<endl;
	}
}