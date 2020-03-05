#include <stdio.h>
#include <math.h>
long long ex(long long k) {
	int i,sum=1;
	for (i=1;i<k;i++) sum*=10;
	return sum;
}
int main() {
	//freopen("a.out","w",stdout);
	long long i,j,k,t,n,entry;
	long long a[6],b[6],c[6];
	a[0]=b[0]=c[0]=0;
	c[1]=9;
	for (i=2;i<6;i++) c[i]=10*c[i-1];
	for (i=1;b[i-1]<=2147483647&&i<6;i++) {
		b[i]=b[i-1]+a[i-1]*c[i]+c[i]*(c[i]+1)*i/2;
		a[i]=a[i-1]+c[i]*i;
	}
	for (scanf("%lld",&t);t;t--) {
		scanf("%lld",&n);
		for (i=1;i<6;i++) {
			if (b[i]>n) break;
		}
		n-=b[i-1];
		for (j=(double)(-(i+2*a[i-1])+sqrt((double)(i+2*a[i-1])*(i+2*a[i-1])+8*n))/(2.0*i)-1;a[i-1]*(j+1)+(j+1)*(j+2)*i/2 < n;j++) ;
		n-=(a[i-1]*j+j*(j+1)*i/2);
		for (k=1;k<=6;k++) {
			if (n>c[k]*k) n-=c[k]*k;
			else break;
		}
		i=(n-1)/k;
		j=(n-1)%k;
		entry = ex(k)+i;
		for (i=k-1-j;i;i--) entry/=10;
		printf("%d\n",entry%10);
	}
}