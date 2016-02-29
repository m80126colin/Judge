#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	int i;
	string s;
	while (cin>>s) {
		ox=1;
		for (i=0;i<=s.size()/2;i++) {
			if (s[i]!=s[s.size()-i-1]) {
				ox=0;
				break;
			}
		}
		if (ox) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}