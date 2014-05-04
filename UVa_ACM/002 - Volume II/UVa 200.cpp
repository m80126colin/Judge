#include <iostream>
#include <string>
using namespace std;

bool ox[26];
string s[10001],t;

int main() {
	int i,j,maxs,maxlen;
	maxs=1,maxlen=0;
	for (cin>>s[0];cin>>t;s[maxs++]=t) {
		if (t=="#") break;
		if (t.size()>maxlen) maxlen=t.size();
	}
	for (i=0;i<maxlen;i++) {
		for (j=0;j<maxs;j++) {
			if (i>=s[j].size()) continue;
			else if (ox[s[j][i]-'A']) continue;
			else {
				cout<<s[j][i];
				ox[s[j][i]-'A']=1;
			}
		}
	}
	cout<<endl;
}