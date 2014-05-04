/*
ID: m80126c2
PROG: calfflac
LANG: C++
*/
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

ifstream cin("calfflac.in");
ofstream cout("calfflac.out");

int mi,mj,ml;
string s;

void cmp(const int& x,const int& y,const int& z) {
	if (z>ml) mi=x,mj=y,ml=z;
	return;
}

bool cmp2(char x,char y) {
	if (x>='A'&&x<='Z') x+='a'-'A';
	if (y>='A'&&y<='Z') y+='a'-'A';
	if (x==y) return 1;
	return 0;
}

int findalpha(int x) {
	while (x>=0&&!isalpha(s[x])) x--;
	return x;
}

int findalpha2(int x) {
	while (x<s.size()&&!isalpha(s[x])) x++;
	return x;
}

void ispal(const int& x) {
	int i,j,tmi,tmj,tml;
	i=j=x,tml=-1;
	while (cmp2(s[i],s[j])) {
		tmi=i,tmj=j,tml+=2;
		cmp(tmi,tmj,tml);
		i=findalpha(i-1);
		if (i<0) {
			cmp(tmi,tmj,tml);
			return;
		}
		j=findalpha2(j+1);
		if (j>=s.size()) {
			cmp(tmi,tmj,tml);
			return;
		}
	}
	return;
}

void ispal2(const int& x,const int& y) {
	int i,j,tmi,tmj,tml;
	i=x,j=y,tml=0;
	while (cmp2(s[i],s[j])) {
		tmi=i,tmj=j,tml+=2;
		cmp(tmi,tmj,tml);
		i=findalpha(i-1);
		if (i<0) {
			cmp(tmi,tmj,tml);
			return;
		}
		j=findalpha2(j+1);
		if (j>=s.size()) {
			cmp(tmi,tmj,tml);
			return;
		}
	}
	return;
}

int main() {
	int i;
	string t;
	s="";
	while (getline(cin,t)) s+=t+"\n";
	mi=mj=ml=0;
	for (i=0;i<s.size();i++) {
		if (isalpha(s[i])) ispal(i);
	}
	for (i=0;i<s.size();i++) {
		int k=findalpha2(i+1);
		if (isalpha(s[i])&&k<s.size()&&s[i]==s[k]) ispal2(i,k);
	}
	cout<<ml<<endl;
	for (;mi<=mj;mi++) cout<<s[mi];
	cout<<endl;
}