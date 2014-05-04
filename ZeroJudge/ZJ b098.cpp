#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int t,i,a;
	for (cin>>t;t;t--) {
		cin>>i;
		cin.ignore(1);
		getline(cin,n);
		for (a=0;a<n.size();a++) {
			n[a]-=i;
			if (n[a]<'A') n[a]+=26;
		}
		cout<<n<<endl;
	}
}