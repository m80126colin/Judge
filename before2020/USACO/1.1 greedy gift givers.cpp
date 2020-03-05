/*
ID: m80126c2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin ("gift1.in");
ofstream fout ("gift1.out");

struct peo{
	string nam;
	int mon;
}p[11];

int main() {
	string s;
	int np,i,j,k,a,b;
	fin>>np;
	for (i=1;i<=np;i++) fin>>p[i].nam,p[i].mon=0;
	for (i=1;i<=np;i++) {
		fin>>s>>a>>b;
		for (j=1;j<=np;j++) if (p[j].nam==s) break;
		if (b) p[j].mon-=(a/b)*b;
		for (k=1;k<=b;k++) {
			fin>>s;
			for (j=1;j<=np;j++) if (p[j].nam==s) break;
			p[j].mon+=a/b;
		}
	}
	for (i=1;i<=np;i++) fout<<p[i].nam<<" "<<p[i].mon<<endl;
}