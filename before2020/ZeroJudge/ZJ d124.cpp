#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string n;
	while (getline(cin,n)) {
		for(i=j=0;j<n.size();j++) {
			if (n[j]>='0'&&n[j]<='9') i+=n[j]-48;
		}
		if (i%3) printf("no\n");
		else printf("yes\n");
	}
}