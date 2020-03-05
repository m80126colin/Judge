#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	bool ox;
	string n;
	int a,b,c;
	double x,y,z;
	while (getline(cin,n)) {
		x=y=0;
		for (a=0;a<n.size();a++) {
			c=0;
			ox=0;
			if(n[a]>='0'&&n[a]<='9') {
				for (b=0;n[a]!=':';a++) {
					b+=n[a]-48;
					if (n[a+1]>='0'&&n[a+1]<='9') b*=10;
				}
			}
			if (n[a++]==':') {
				for (z=0;n[a]!=' '&&a<n.size();a++) {
					if (c) c++;
					if (n[a]>='0'&&n[a]<='9') z+=n[a]-48;
					if (a+1<n.size()) {
						if (n[a+1]>='0'&&n[a+1]<='9') z*=10;
					}
					if (n[a]=='-') ox=1;
					if (n[a]=='.') c++;
				}
				if (c) {
					c=pow((double) 10,c-1);
					z/=c;
				}
				if (ox) z=-z;
				if (b%2) y+=z;
				else x+=z;
			}
		}
		cout<<noshowpoint<<y-x<<endl;
	}
}