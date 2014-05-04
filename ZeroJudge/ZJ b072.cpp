#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	string a,b;
	int m,n;
	while (cin>>m>>n&&m&&n) {
		for (a="";m;m--) {
			cin>>b;
			a+=b;
		}
		for (b="";n;n--) {
			cin>>m;
			b+=a[m-1];
		}
		cout<<b<<endl;
	}
}