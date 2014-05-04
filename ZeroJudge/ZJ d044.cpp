#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	static bool ox[1000001];
	int i,n,a;
	for (i=1;i<=1000000;i++) ox[i]=1;
	for (n=1;n<=1000000;n++) {
		for (a=i=n;i;i/=10) a+=i%10;
		ox[a]=0;
	}
	for (i=1;i<=1000000;i++) {
		if (ox[i]) printf("%d\n",i);
	}
}