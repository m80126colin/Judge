#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int ox[10],i,j,k;
	while (getline(cin,s)) {
		memset(ox,0,sizeof(ox));
		for (i=0;i<s.size();i++) ox[s[i]-48]++;
		for (i=j=k=0;k<10;k++) {
			if (ox[k]>i) {
				j=k;
				i=ox[k];
			}
		}
		cout<<j;
		for (k=1;k<i;k++) cout<<"-"<<j;
		cout<<endl;
	}
}