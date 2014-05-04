#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,t;
	while (cin>>n) {
		for (t=sqrt(n+0.001);t>1;t--) {
			if (n%t==0) break;
		}
		if (t==1) cout<<"質數"<<endl;
		else cout<<"非質數"<<endl;
	}
}