#include <iostream>
#include <string>
using namespace std;

char a[1000000];

int main() {
	bool color;
	int p,t,s,w,b;
	for (cin>>p;p;p--) {
		s=0;
		for (w=1000000;w;w--) a[w]='0';
		for (cin>>t;t;t--) {
			cin>>w;
			if (w>0) a[w]='b';
			else a[-w]='r';
		}
		b=1;
		for (w=1000000;w;w--) {
			if (a[w]=='b') {
				if (b==1) {
					b=0;
					color=true;
					s++;
				}
				if (color==false) {
					color=true;
					s++;
				}
			}
			if (a[w]=='r') {
				if (b==1) {
					b=0;
					color=false;
					s++;
				}
				if (color==true) {
					color=false;
					s++;
				}
			}
		}
		cout<<s<<endl;
	}
}