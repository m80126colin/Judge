#include <iostream>
#include <string>
using namespace std;

bool ox;
string n;
int a[5000],t;

int re() {
	a[a[0]-1]=0;
	a[0]-=2;
	ox=1;
	return 0;
}

int main() {
	while (getline(cin,n)) {
		for (a[0]=4999;a[0];a[0]--) a[a[0]]=0;
		a[0]=1;
		for (t=0;t<n.size();t++) {
			ox=0;
			while (n[t]>='0'&&n[t]<='9') {
				a[a[0]]+=n[t]-48;
				if ((t<n.size()-1)&&n[t+1]>='0'&&n[t+1]<='9') a[a[0]]*=10;
				t++;
				ox=1;
			}
			if (n[t]=='+') {
				a[a[0]-2]+=a[a[0]-1];
				re();
			}
			if (n[t]=='-') {
				a[a[0]-2]-=a[a[0]-1];
				re();
			}
			if (n[t]=='*') {
				a[a[0]-2]*=a[a[0]-1];
				re();
			}
			if (n[t]=='/') {
				a[a[0]-2]/=a[a[0]-1];
				re();
			}
			if (n[t]=='%') {
				a[a[0]-2]%=a[a[0]-1];
				re();
			}
			if (ox) a[0]++;
		}
		cout<<a[1]<<endl;
	}
}