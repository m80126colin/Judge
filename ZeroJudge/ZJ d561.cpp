/*
Problem: d561
Language: C++
Result: AC (1ms, 740KB) on ZeroJudge
Author: m80126colin at 2010-07-09 18:05:32
Solution: String
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	string s;
	while (cin>>s) {
		for (i=0;i<s.size();i++) if (s[i]=='.') break;
		while (s.size()-i<=2) s+="0";
		if (s.size()-i>2) {
			if (s[i+3]>='5') s[i+2]++;
			if (s[i+2]>'9') s[i+1]++,s[i+2]='0';
			if (s[i+1]>'9') s[i-1]++,s[i+1]='0';
			s=s.substr(0,i+3);
		}
		if (s=="-0.00") s="0.00";
		cout<<s<<endl;
	}
}