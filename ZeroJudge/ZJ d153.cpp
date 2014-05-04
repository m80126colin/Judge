#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t,n,i,a[40001];
	for (cin>>t;t;t--) {
		for (cin>>n,i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d\n",a[(n+1)/2]);
	}
}