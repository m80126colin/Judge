#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	bool ox;
	static int n,i,j,x[200002];
	ox=0;
	while (cin>>n) {
		j=n;
		for (memset(x,0,sizeof(x));n;n--) scanf("%d",&x[n]);
		sort(x+1,x+j+1);
		x[j+1]=0;
		if (ox) printf("\n");
		for (i=1;i<=j;i++) {
			printf("%d ",x[i]);
			x[0]=1;
			for (i;x[i]==x[i+1];i++) x[0]++;
			printf("%d\n",x[0]);
		}
		ox=1;
	} 
}