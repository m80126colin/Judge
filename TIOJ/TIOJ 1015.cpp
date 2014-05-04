#include <iostream>
using namespace std;

int main() {
	long long m,n,i;
	while (cin>>m>>n&&(m||n)) {
		i=min(m,n);
		cout<<(2*i*i*i+(3-3*m-3*n-6)*i*i+(6*m*n+3*m+3*n+1)*i)/6<<endl;
	}
}