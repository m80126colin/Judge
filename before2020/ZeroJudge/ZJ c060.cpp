#include <iostream>
using namespace std;

int main() {
	int x[9],t;
	bool z;
	while (cin>>x[8]>>x[7]>>x[6]>>x[5]>>x[4]>>x[3]>>x[2]>>x[1]>>x[0]) {
		z=true;
		for (t=8;t>=0;t--) {
			if (z) {
				if (x[t]) {
					if (t) {
						if (x[t]==-1) cout<<"-";
						if ((x[t]>1)||(x[t]<-1)) cout<<x[t];
						if (t>1) cout<<"x^"<<t;
						else cout<<"x";
					}
					else cout<<x[t];
					z=false;
				}
			}
			else {
				if (x[t]) {
					if (x[t]>0) cout<<" + ";
					if (x[t]<0) cout<<" - ";
					if ((x[t]>1)||(x[t]<-1)||(t==0)) cout<<abs(x[t]);
					if (t>1) cout<<"x^"<<t;
					if (t==1) cout<<"x";
				}
			}	
		}
		if (z) cout<<0;
		cout<<endl;
	}
}