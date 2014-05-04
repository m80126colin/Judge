#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	char ch;
	int a;
	while (getline(cin,n)) {
		for (a=0;a<n.size();a++) {
			ch=n[a]-7;
			cout<<ch;
		}
		cout<<endl;
	}
}