#include <iostream>
#include <string>
using namespace std;

int main() {
	bool t,ox,x;
	string n;
	int a,i;
	t=0;
	while (cin>>n) {
		ox=x=0;
		if (t) cout<<endl;
		a=(n[n.size()-4]-48)*1000+(n[n.size()-3]-48)*100+(n[n.size()-2]-48)*10+(n[n.size()-1]-48);
		if (a%400==0||(a%100&&a%4==0)) {
			ox=x=1;
			cout<<"This is leap year.\n";
		}
		for (i=0,a=0;i<n.size();i++) a+=n[i]-48;
		if (a%3==0&&(n[n.size()-1]=='0'||n[n.size()-1]=='5')) {
			ox=1;
			cout<<"This is huluculu festival year.\n";
		}
		for (i=0,a=0;i<n.size();i+=2) {
			if ((n.size()-i)>1) a+=(n[i]-48)-(n[i+1]-48);
			else a+=n[i]-48;
		}
		if (x&&a%11==0&&(n[n.size()-1]=='0'||n[n.size()-1]=='5')) {
			ox=1;
			cout<<"This is bulukulu festival year.\n";
		}
		if (ox==0) cout<<"This is an ordinary year.\n";
		t=1;
	}
}