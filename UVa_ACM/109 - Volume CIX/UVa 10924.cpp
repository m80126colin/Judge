#include <iostream>
#include <string>
using namespace std;

int main() {
	char l;
	string n;
	int a,b;
	a=0;
	while (cin.get(l)) {		
			if (l>='a'&&l<='z') a+=l-96;
			if (l>='A'&&l<='Z') a+=l-38;
			if (l=='\n') {
				for (b=a;b;b--) {	
					if (b==1) cout<<"It is a prime word."<<endl;
					if (a%b==0&&b!=1&&b!=a) {cout<<"It is not a prime word."<<endl;break;}
				}
				a=0;
			}
	}
}