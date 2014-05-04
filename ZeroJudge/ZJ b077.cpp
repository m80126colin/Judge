#include <iostream>
using namespace std;

int main() {
	long long m,n;
	while (cin>>m>>n&&(m||n)) {
		if (m>n) cout<<"Unfair";
		else cout<<"Fair";
		cout<<endl;
	}
}