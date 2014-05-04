/*
Problem: d586 "«¢±K¥Ê¬ü»y" from jack1
Language: C++
Result: AC (22ms, 794KB) on ZeroJudge
Author: m80126colin at 2010-07-12 19:45:53
Solution: String Processing
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	char ch;
	int s3[27],i,j,n,m;
	string s1=" mjqhofawcpnsexdkvgtzblryui",s2=" uzrmatifxopnhwvbslekycqjgd";
	for (i=1;i<s2.size();i++) s3[s2[i]-'a'+1]=i;
	while (~scanf("%d",&n)) {
		for (;n;n--) {
			scanf("%d ",&m);
			ch=cin.peek();
			if (ch>='a'&&ch<='z') {
				for (j=0;m;m--) cin>>ch,j+=s3[ch-'a'+1];
				printf("%d\n",j);
			}
			else {
				for (;m;m--) scanf("%d",&j),putchar(s1[j]);
				puts("");
			}
		}
	}
}