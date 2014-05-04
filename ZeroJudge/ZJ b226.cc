#include <iostream>
using namespace std;

int main() {
	int l,w,x,y;
	while (cin>>l>>w>>x>>y&&(l||w||x||y)) {
		if ((l%x==0&&w%y==0)||(w%x==0&&l%y==0)) cout<<l*w/x/y<<endl;
		else cout<<-1<<endl;
	}
}