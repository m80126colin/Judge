#include <iostream>
using namespace std;

int main() {
	long long n;
	cin>>n;
	while(n>0) {
		if (n==1) cout<<"0%"<<endl;
		else {
			n=25*n;
			cout<<n<<"%"<<endl;
		}
		cin>>n;	
	}
}