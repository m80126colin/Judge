#include <iostream>
using namespace std;

int main() {
	int k,m,m2,m5,t;
	while (cin>>k) {
		for (m2=0;k%2==0;m2++) k/=2;
		for (m5=0;k%5==0;m5++) k/=5;
		t=1;
		for (m=3%k;m;t++) m=(m*10+3)%k;
		m=max(m2,m5);
		k=t+m;
		cout<<k<<" "<<t<<" "<<m<<endl;
	}
}