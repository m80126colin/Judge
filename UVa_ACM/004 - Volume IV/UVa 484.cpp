#include <iostream>
using namespace std;

int main() {
	char a;
	static int b,n[50001],t[50001];
	for (n[0]=50000;n[0];n[0]--) n[n[0]]=0;
	t[0]=1;
	while (cin>>b) {
		if (n[b]==0) {
			t[t[0]++]=b;
		}
		n[b]++;
		cin.get(a);
		if (a=='\n') break;
	}
	for (n[0]=1;n[0]<t[0];n[0]++) {
		cout<<t[n[0]]<<" "<<n[t[n[0]]]<<endl;
	}
}