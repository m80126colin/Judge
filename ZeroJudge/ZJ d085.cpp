#include <iostream>
using namespace std;

bool pr[46341];
int p[4793];

int main() {
	bool oxi,ox;
	long long n,n1,i,j,k,t;
	memset(pr,1,sizeof(pr));
	pr[0]=pr[1]=0;
	k=1;
	for (i=2;i<=46340;i++) {
		if (pr[i]) {
			p[k]=i;
			k++;
			for (j=2;j*i<=46340;j++) pr[j*i]=0;
		}
	}
	while (scanf("%lld",&n)!=EOF) {
		oxi=0;
		ox=1;
		k=1;
		if (n<0) {
			n*=-1;
			oxi=1;
			ox=0;
		}
		n1=n;
		for (i=1;p[i]*p[i]<=n&&i<4793;i++) {
			t=0;
			while (!(n%p[i])) {
				t++;
				n/=p[i];
				ox=0;
			}
			for (j=1;j<=t/2;j++) k*=p[i];
		}
		if (k>1) cout<<k;
		if (n1/(k*k)>1) cout<<"_/"<<n1/(k*k);
		if (ox&&n<=1) cout<<n;
		if (oxi) cout<<"i";
		cout<<endl;
	}
}