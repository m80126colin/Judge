#include <iostream>
#include <math.h>
using namespace std;

int re(int x) {
	if (x/2) re(x/2);
	cout<<x%2;
	return 0;
}

int main() {
	int j;
	double i;
	while (cin>>i) {
		j=floor(i);
		re(j);
		i-=j;
		cout<<'.';
		j=2;
		while (i) {
			i*=2;
			if (i>=1) {
				cout<<1;
				i-=floor(i);
			}
			else cout<<0;
		}
		cout<<endl;
	}
}