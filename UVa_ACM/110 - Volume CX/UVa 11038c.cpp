#include <stdio.h>
long long count(long long n,long long value) {
	long long one,ten,sum=0;
	if (n<=0) return 1;
	one = n%10;
	ten = (n/=10);
	sum = ten*value;
	while (ten) {
		if (!(ten%10)) sum+=(one+1)*value;
		ten/=10;
	}
	return sum + count(n-1,value*10);
}
int main() {
	long long m,n;
	while (scanf("%lld%lld",&m,&n),m>=0||n>=0) printf("%lld\n",count(n,1)-count(m-1,1)+(m==0));
}