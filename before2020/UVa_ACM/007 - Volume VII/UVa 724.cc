#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin("Q724.cc");

int main() {
	int i,j;
	string s[101];
	for (i=0;getline(fin,s[i]);i++) {
		if (s[i][0]!='#') cout<<s[i]<<endl;
	}
	for (i--;i>=0;i--) {
		for (j=s[i].size();j;j--) cout<<s[i][j-1];
		cout<<endl;
	}
}