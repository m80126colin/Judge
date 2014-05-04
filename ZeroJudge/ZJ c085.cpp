#include <iostream>
using namespace std;

int main() {
	bool ox;
	static int z,i,m,l,t,s,j,n[10000];
	t=1;
	while (cin>>z>>i>>m>>l&&(z||i||m||l)) {
		ox=1;
		for (j=0;ox;j++) {
			n[j]=l;
			l=(z*l+i)%m;
			for (s=1;s<=j;s++) {
				if (n[j-s]==n[j]) {
					ox=0;
					break;
				}
			}
		}
		cout<<"Case "<<t++<<": "<<s<<endl;
	}
}