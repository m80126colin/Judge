#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double x,y,z,t;
	int r,g,b,i,n;
	while (cin>>n) {
		t=0;
		for (i=n*n;i;i--) {
			scanf("%d %d %d",&r,&g,&b);
			x=0.5149*r+0.3244*g+0.1607*b;
			y=0.2654*r+0.6704*g+0.0642*b;
			z=0.0248*r+0.1248*g+0.8504*b;
			printf("%.4f %.4f %.4f\n",x,y,z);
			t+=y;
		}
		printf("The average of Y is %.4f\n",t/=(n*n));
	}
}