#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	string s,t;
	getline(cin,s);
	getline(cin,t);
	for (i=min(s.size(),t.size());i;i--) {
		if (s.substr(0,i)==t.substr(t.size()-i,i)) {
			printf("%d\n",i);
			break;
		}
	}
	if (!i) printf("0\n");
}