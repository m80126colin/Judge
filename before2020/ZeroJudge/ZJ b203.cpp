#include <iostream>
#include <string>
using namespace std;

int main() {
	int k,m,i;
	string s1,s2,s;
	for (cin>>k,i=1,cin.ignore(1);i<=k;i++) {
		cout<<"DATA SET #"<<i<<":\n";
		getline(cin,s1,'#');
		getline(cin,s2,'\n');
		for (cin>>m,cin.ignore(1);m;m--) {
			getline(cin,s);
			if (s.size()>=s1.size()+s2.size()) {
				if (s.substr(0,s1.size())==s1&&s.substr(s.size()-s2.size())==s2) cout<<"POSSIBLE\n";
				else cout<<"IMPOSSIBLE\n";
			}
			else cout<<"IMPOSSIBLE\n";
		}
	}
}