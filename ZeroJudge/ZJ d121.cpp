#include <iostream>
using namespace std;

bool pr[46341];
int p[4793];

int main() {
	bool ox;
	long long n,i,j,k;
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
	while (cin>>n&&n) {
		ox=1;
		cout<<n<<" = ";
		if (n<0) {
			cout<<"-1";
			n*=-1;
			ox=0;
		}
		for (i=1;p[i]*p[i]<=n&&i<4793;i++) {
			while (!(n%p[i])) {
				if (!ox) cout<<" x ";
				cout<<p[i];
				n/=p[i];
				ox=0;
			}
		}
		if (ox||n>1) {
			if (!ox) cout<<" x ";
			cout<<n;
		}
		cout<<endl;
	}
}