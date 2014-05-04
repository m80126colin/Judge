#include <iostream>
#include <string>
using namespace std;

int main() {
	string n[101];
	int t,m,i,j;
	m=0;
	for (t=0;getline(cin,n[t+1])&&!cin.eof();t++) {
		if (n[t+1]=="\032") break;
		i=n[t+1].size();
		m=max(i,m);
	}
	for (i=0;i<m;i++) {
		for (j=t;j;j--) {
			if (i>n[j].size()-1) cout<<" ";
			else cout<<n[j][i];
		}
		cout<<endl;
	}
}