#include <iostream>
using namespace std;

int main() {
	int n,i,j,t1,t2;
	while (cin>>i>>j) {
		t1=t2=0;
		n=1;
		i+=j;
		if (i>8) {
			t1=i;
			t2=n;
		}
		for (n=2;n<=7;n++) {
			cin>>i>>j;
			i+=j;
			if (i>8&&i>t1) {
				t1=i;
				t2=n;
			}
		}
		cout<<t2<<endl;
	}
}