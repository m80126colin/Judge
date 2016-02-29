#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	static int n[100002],j,i;
	for (i=1;scanf("%d",&n[i])!=EOF;i++) ;
	sort(n+1,n+i);
	i--;
	printf("%d",n[i]);
	for (i--;i;i--) printf(" %d",n[i]);
}