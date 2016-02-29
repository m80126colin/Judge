#include <stdio.h>
#include <string.h>
int main() {
	char a[13][10]={"","Winter","Winter","Spring","Spring","Spring","Summer","Summer","Summer","Autumn","Autumn","Autumn","Winter"};
	int n;
	while (scanf("%d",&n)!=EOF) puts(a[n]);
}