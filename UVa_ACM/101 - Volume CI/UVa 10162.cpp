#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int n,k[21]={0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4,4};
	while (getline(cin,a)&&a!="0") {
		if (a.size()>=2) n=(a[a.size()-2]-48)*10+a[a.size()-1]-48;
		else n=a[a.size()-1]-48;
		n=((n/20)*k[20]+k[n%20])%10;
		cout<<n<<endl;
	}
}