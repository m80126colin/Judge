#include <iostream>
using namespace std;

int main() {
	int a,b,c,t;
	while (scanf("%d %d %d",&a,&b,&c)&&a&&b&&c) {
		while (a%b) {
			t=b;
			b=a%b;
			a=t;
		}
		if (c%b) printf("No\n");
		else printf("Yes\n");
	}
}