#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	static int n[60001],t,s;
	while (cin>>t&&t) {
		for (n[0]=60000;n[0];n[0]--) n[n[0]]=1;
		n[1]=t;
		for (n[0]=2;n[1]!=1;n[0]++) {
			s=1;
			while (n[1]%n[0]==0) {
				n[n[0]]+=pow((double) n[0],s++);
				n[1]/=n[0];
			}
		}
		for (n[0]--;n[0]>=2;n[0]--) n[1]*=n[n[0]];
		n[1]-=t;
		if (n[1]>t) cout<<"盈數"<<endl;
		else if (n[1]==t) cout<<"完全數"<<endl;
		else cout<<"虧數"<<endl;
	}
}