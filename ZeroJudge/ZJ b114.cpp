#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int a1,a2,b1,b2;
	double x;
	while (scanf("%d\n%d\n%d\n%d",&a1,&a2,&b1,&b2)!=EOF) {
		x=(double) (b1-b2)/(a2-a1);
		cout<<x<<endl<<a1*x+b1<<endl;
	}
}