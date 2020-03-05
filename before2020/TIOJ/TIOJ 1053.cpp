#include <iostream>
using namespace std;

int main() {
	int p,q;
	while (cin>>p>>q) {
		if (p>q) p^=q^=p^=q;
		cout<<( (q%p) ? "N\n" : "Y\n" );
	}
}