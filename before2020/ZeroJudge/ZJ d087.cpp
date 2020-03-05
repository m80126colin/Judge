#include <iostream>
#include <math.h>
using namespace std;

int re (int x,int y=0) {
	int i,j;
	for (i=2;i*i<=x;i++) {
		for (j=0;x%i==0;j++) x/=i;
		while (j) {
			y%=j;
			swap(y,j);
		}
	}
	return x>1 ? 1 : y;
}

int main() {
	int m,n,i,k;
	while (cin>>m>>n&&m) {
		k=re(n,re(m));
		i=pow((double) n,1.0/k)+0.5;
		cout<<(i==1 ? k : (n-1)/(i-1))<<" "<<m*(i+1)-n*i<<endl;
	}
}