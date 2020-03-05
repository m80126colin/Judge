/*
Problem: d625
Language: C++
Result: AC (8ms, 754KB) on ZeroJudge
Author: m80126colin at 2010-07-13 16:14:43
Solution: Straight Forward
*/
#include <iostream>
#include <string>
using namespace std;

int n,i,j;
string s[102];

inline char is() {
	if (s[i][j]=='*') return '*';
	int a[8]={-1,0,1,-1,1,-1,0,1},b[8]={-1,-1,-1,0,0,1,1,1};
	int x,y;
	for (x=y=0;x<8;x++) if (s[i+a[x]][j+b[x]]=='*') y++;
	if (y) return y+'0';
	return '-';
}

int main() {
	s[0]=" ";
	for (cin>>n,i=1;i<=n;s[0]+=" ",i++) cin>>s[i],s[i]=" "+s[i]+" ";
	s[i]=s[0];
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) cout<<is();
		cout<<endl;
	}
}