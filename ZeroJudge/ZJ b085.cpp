#include <iostream>
using namespace std;

int re(int x,int y,int &z) {
	if (x%y) re(y,x%y,z);
	else z=y;
	return 0;
}

int main() {
	int t,x,y,x1,y1;
	for (cin>>t;t;t--) {
		cin>>x>>y>>x1>>y1;
		x-=x1;
		x=abs(x);
		y-=y1;
		y=abs(y);
		if (x&&y) re(max(x,y),min(x,y),x1);
		else x1=max(x,y);
		cout<<x1+1<<endl;
	}
}