#include <iostream>
using namespace std;

int main() {
	int i;
	short n,j,m,h[51];
	i=1;
	for (cin>>n;n;cin>>n) {
		h[0]=0;
		for (j=1;j<=n;j++) {
			cin>>h[j];
			h[0]+=h[j];
		}
		h[0]=h[0]/n;
		m=0;	
		for (j--;j;j--) {
			if ((h[j]-h[0])>0) m+=(h[j]-h[0]);
		}
		cout<<"Set #"<<i<<endl;
		cout<<"The minimum number of moves is "<<m<<".\n"<<endl;
		i++;
	}
}