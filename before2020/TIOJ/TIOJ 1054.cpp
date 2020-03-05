#include <iostream>
#include <string>
using namespace std;

string s[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main() {
	string t;
	int i,n;
	while (cin>>t>>n) {
		for (i=0;i<7;i++) if (t==s[i]) break;
		i+=(n%=7),i-=7*(i>6);
		cout<<s[i]<<endl;
	}
}