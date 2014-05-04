#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int b[4],g[4],c[4],j;
	while (cin>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2]>>b[3]>>g[3]>>c[3]) {
		j=2147483647;
		if (j>b[2]+b[3]+c[1]+c[3]+g[1]+g[2]) {
			n="BCG";
			j=b[2]+b[3]+c[1]+c[3]+g[1]+g[2];
		}
		if (j>b[2]+b[3]+g[1]+g[3]+c[1]+c[2]) {
			n="BGC";
			j=b[2]+b[3]+g[1]+g[3]+c[1]+c[2];
		}
		if (j>c[2]+c[3]+b[1]+b[3]+g[1]+g[2]) {
			n="CBG";
			j=c[2]+c[3]+b[1]+b[3]+g[1]+g[2];
		}
		if (j>c[2]+c[3]+g[1]+g[3]+b[1]+b[2]) {
			n="CGB";
			j=c[2]+c[3]+g[1]+g[3]+b[1]+b[2];
		}
		if (j>g[2]+g[3]+b[1]+b[3]+c[1]+c[2]) {
			n="GBC";
			j=g[2]+g[3]+b[1]+b[3]+c[1]+c[2];
		}
		if (j>g[2]+g[3]+c[1]+c[3]+b[1]+b[2]) {
			n="GCB";
			j=g[2]+g[3]+c[1]+c[3]+b[1]+b[2];
		}
		cout<<n<<" "<<j<<endl;
	}
}