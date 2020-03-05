#include <iostream>
using namespace std;

long long n[14];

int f(int x) {
	if (x==1) return 0;
	n[n[0]]*=x;
	f(x-1);
}

int main() {
	for (n[0]=8;n[0]<=13;n[0]++) {
		n[n[0]]=1;
		f(n[0]);
	}
	while (cin>>n[0]) {
		if (n[0]<0) {
			if (n[0]%2) cout<<"Overflow!"<<endl;
			else cout<<"Underflow!"<<endl;
		}
		else {
			if (n[0]<8) cout<<"Underflow!"<<endl;
			if (n[0]>13) cout<<"Overflow!"<<endl;
			if ((n[0]>=8)&&(n[0]<=13)) cout<<n[n[0]]<<endl;
		}
	}
}