#include <iostream>
using namespace std;

int main() {
	int t,i,j,k,m,n;
	while (cin>>n) {
		i=j=t=0,m=1;
		k=(j+300-n)/100;
		i+=k*100;
		j+=300-n-k*100;
		if (j<0&&!t) t=m;
		for (m++;m<=12;m++) {
			cin>>n;
			k=(j+300-n)/100;
			i+=k*100;
			j+=300-n-k*100;
			if (j<0&&!t) t=m;
		}
		if (t) cout<<"-"<<t<<endl;
		else cout<<i*1.2+j<<endl;
	}
}