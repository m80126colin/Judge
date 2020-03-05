#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int a,b;
	while (getline(cin,n)) {
		for (a=b=0;b<n.size();b++) {
			if (n[b]+a-48>120) {cout<<b<<" "<<120-a<<endl;break;}
			else a+=n[b]-48;
		}
	}
}