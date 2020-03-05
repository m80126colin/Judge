#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	bool ox;
	int n,m,s,g,t;
	while (cin>>n>>m) {
		for (ox=0;n<=m;n++) {
			t=g=0;
			for (s=n;s;s/=10) t++;
			for (s=n;s;s/=10) g+=pow(s%10+0.000001,t);
			if (ox&&n==g) cout<<" ";
			if (n==g) {
				cout<<n;
				ox=1;
			}
			
		}
		if (ox==0) cout<<"none";
		cout<<endl;
	}
}