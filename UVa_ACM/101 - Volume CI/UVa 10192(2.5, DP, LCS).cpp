#include <iostream>
#include <string>
using namespace std;

int main() {
	int lcs[101][101],i,j,t;
	string s1,s2;
	for (t=1;getline(cin,s1),s1!="#";t++) {
		memset(lcs,0,sizeof(lcs));
		getline(cin,s2);
		for (i=0;i<s1.size();i++) {
			for (j=0;j<s2.size();j++) lcs[i+1][j+1]=( (s1[i]==s2[j]) ? lcs[i][j]+1 : max(lcs[i][j+1],lcs[i+1][j]));
		}
		printf("Case #%d: you can visit at most %d cities.\n",t,lcs[s1.size()][s2.size()]);
	}
}