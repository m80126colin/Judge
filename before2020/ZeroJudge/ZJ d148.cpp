#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
	int i;
	string a,b,s;
	a=s="";
	while (getline(cin,b)) a+=b;
	for (i=0;i<a.size();i++) {
		if (isalpha(a[i])) s+=a[i];
	}
	cout<<s<<endl;
}