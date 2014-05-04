#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n,i,s;
	while (cin>>n) {
		for (i=s=1;i<=n;i++) {
			s*=i;
			while (s%10==0) s/=10;
			if (s/100000) s%=100000;
		}
		cout<<setw(5)<<n<<" -> "<<s%10<<endl;
	}
}