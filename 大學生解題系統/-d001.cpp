#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	string s;
	while (getline(cin,s)) {
		for (i=s.size();i;i--) cout<<s[i-1];
		cout<<endl;
	}
}