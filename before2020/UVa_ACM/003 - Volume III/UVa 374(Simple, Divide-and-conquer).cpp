/**
 *  @judge UVa
 *  @id 374
 *  @tag Simple, Divide and conquer
 */
#include <iostream>
using namespace std;

int main() {
	long long b,p,m,s[65],t;
	while (cin>>b>>p>>m) {
		for (s[0]=1;p;s[0]++) {
			s[s[0]]=b;
			for (t=2;t<=p;t*=2) s[s[0]]=(s[s[0]]*s[s[0]])%m;
			p-=(t/2);
		}
		t=1;
		while (--s[0]) t=(t*s[s[0]])%m;
		cout<<t<<endl;
	}
}