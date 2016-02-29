#include <iostream>
using namespace std;

int main() {
	char a;
	bool ox[101];
	int m,n,pi,i,x;
	int l[51],r[51];
	for (cin>>m;m;m--) {
		cin>>n;
		for (x=n;n;n--) ox[n]=1;
		for (cin>>n;n;n--) {
			cin>>pi;
			for (i=1;i<=pi;i++) cin>>l[i];
			for (i=1;i<=pi;i++) cin>>r[i];
			cin>>a;
			if (a=='=') {
				for (i=1;i<=pi;i++) ox[l[i]]=ox[r[i]]=0;
			}
		}
		ox[0]=0;
		for (i=1;i<=x;i++) {
			if (ox[0]==1&&ox[i]==1) {
				pi=0;
				break;
			}
			if (ox[i]==1) {
				ox[0]=1;
				pi=i;
			}
		}
		if (ox[0]==0) pi=0;
		cout<<pi<<endl;
		if (m!=1) cout<<endl;
	}
}