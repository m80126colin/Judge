#include <iostream>
using namespace std;

int main() {
	int a1,a2,a3,b1,b2,b3,t;
	while (cin>>a1>>a2>>a3>>b1>>b2>>b3&&(a1||a2||a3||b1||b2||b3)) {
		for (t=1;1;t++) {
			b1=b1-(a2-b3);
			if (b1<=0) break;
			a1=a1-(b2-a3);
			if (a1<=0) break;
		}
		if (a1<=0) cout<<"You lose in "<<t<<" round(s).";
		if (b1<=0) cout<<"You win in "<<t<<" round(s).";
		cout<<endl;
	}
}