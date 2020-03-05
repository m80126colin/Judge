#include <iostream>
using namespace std;

int p[10001],num[10000];

int main() {
	bool ox;
	int n,i,j,k;
	while (scanf("%d:",&n),n) {
		memset(p,0,sizeof(p));
		ox=1;
		for (i=0;i<n;i++) cin>>num[i],p[num[i]]=i;
		for (i=0;i<n;i++) {
			for (j=i+1;j<n;j++) {
				k=num[j]+(num[j]-num[i]);
				if ( k>=0 && k<n )
					if (p[k]>j) ox=0;
			}
		}
		printf( ((ox) ? "yes\n" : "no\n") );
	}
}