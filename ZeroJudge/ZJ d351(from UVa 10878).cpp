#include <iostream>
#include <string>
using namespace std;

int main() {
	char b;
	short a;
	string n,p;
	a=0,p="";
	while (getline(cin,n)) {
		b=0;
		if (n=="___________") a++;
		else {
			if (n[1]=='o') b+=128;
			if (n[2]=='o') b+=64;
			if (n[3]=='o') b+=32;
			if (n[4]=='o') b+=16;
			if (n[5]=='o') b+=8;
			if (n[7]=='o') b+=4;
			if (n[8]=='o') b+=2;
			if (n[9]=='o') b+=1;
			p+=b;
		}
		if (a==2) {
			cout<<p<<endl;
			a=0,p="";
		}	
	}
}