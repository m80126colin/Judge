/*
Problem: d566
Language: C++
Result: AC (19ms, 1157KB) on ZeroJudge
Author: m80126colin at 2010-07-09 19:38:50
Solution: Straight Forward
*/
#include <iostream>
#include <string>
using namespace std;

struct peo{
	string name,stu;
}p[10001];
string s[10001];

int main() {
	bool ox[10001];
	int n,i,j,k,t1,t2;
	t1=t2=0;
	memset(ox,0,sizeof(ox));
	for (cin>>n,i=1;i<=n;i++) cin>>p[i].name>>p[i].stu;
	for (j=0,i=n;i;i--) {
		for (k=0;k<j;k++) if (p[i].name==s[k]) break;
		if (k>=j) {
			s[j]=p[i].name;
			j++;
			if (p[i].stu=="AC") t1++;
		}
		if (p[i].stu=="AC"&&!ox[k]) t2++,ox[k]=1;
	}
	cout<<t1*100/t2<<"%\n";
}