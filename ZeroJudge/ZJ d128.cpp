#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	while (scanf("%d %d %d",&a,&b,&c)!=EOF) {
		a=max(max(max(a*10+b+c,a+b*10+c),max((a*10+b)*c,a*(b*10+c))),max(max(a+b+c,a+b*c),max(a*b+c,a*b*c)));
		printf("%d\n",a);
	}
}