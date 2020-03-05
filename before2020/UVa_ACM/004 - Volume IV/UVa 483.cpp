#include <iostream>
#include <string>
using namespace std;

int main() {
	char a;
	string n;
	int i;
	while (cin>>n&&cin.get(a)) {
		for (i=n.size()-1;i>=0;i--) cout<<n[i];
		cout<<a;
	}
}