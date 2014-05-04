#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int i;
	string s;
	map <string,int> m;
	for (s="a",i=1,s[0]='a';s[0]<='z';s[0]++,i++) m[s]=i;
	for (s="aa",s[0]='a';s[0]<='y';s[0]++) {
		for (s[1]=s[0]+1;s[1]<='z';s[1]++,i++) m[s]=i;
	}
	for (s="aaa",s[0]='a';s[0]<='x';s[0]++) {
		for (s[1]=s[0]+1;s[1]<='y';s[1]++) {
			for (s[2]=s[1]+1;s[2]<='z';s[2]++,i++) m[s]=i;
		}
	}
	for (s="aaaa",s[0]='a';s[0]<='w';s[0]++) {
		for (s[1]=s[0]+1;s[1]<='x';s[1]++) {
			for (s[2]=s[1]+1;s[2]<='y';s[2]++) {
				for (s[3]=s[2]+1;s[3]<='z';s[3]++,i++) m[s]=i;
			}
		}
	}
	for (s="aaaaa",s[0]='a';s[0]<='v';s[0]++) {
		for (s[1]=s[0]+1;s[1]<='w';s[1]++) {
			for (s[2]=s[1]+1;s[2]<='x';s[2]++) {
				for (s[3]=s[2]+1;s[3]<='y';s[3]++) {
					for (s[4]=s[3]+1;s[4]<='z';s[4]++,i++) m[s]=i;
				}
			}
		}
	}
	while (cin>>s) cout<<m[s]<<endl;
}