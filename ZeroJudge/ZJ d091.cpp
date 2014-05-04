#include <iostream>
using namespace std;

int main() {
	int a,d,e,g;
	float b,c,x1[11],y1[11],x2[11],y2[11];
	char f;
	for (a=1;cin>>f;a++) {
		if (f=='r') cin>>x1[a]>>y1[a]>>x2[a]>>y2[a];
		if (f=='*') break;
	}
	for (e=1;cin>>b>>c;e++) {
		if ((b+0.0001>9999.9)&&(c+0.0001>9999.9)) break;
		g=1;
		for (d=1;d<a;d++) {
			if ((b>x1[d])&&(b<x2[d])&&(c<y1[d])&&(c>y2[d])) {
				cout<<"Point "<< e <<" is contained in figure "<< d <<endl;
				g=0;
			}
		}
		if (g) cout<<"Point "<<e<<" is not contained in any figure"<<endl;
	}
}