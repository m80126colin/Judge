#include <iostream>
using namespace std;

int main() {
	int t,n,i[1002],p1;
	double p2[1002];
	for (cin>>t;t;t--) {
		for (i[0]=1;i[0]<=1000;i[0]++) {
			i[i[0]]=0;
			p2[i[0]]=0;
		}
		i[0]=1;
		for (cin>>n;n;n--) {
			cin>>p1>>p2[0];
			p2[0]/=p1;
			for (p1=i[0];p2[0]>p2[p1];p1--) {
				p2[p1+1]=p2[p1];
				i[p1+1]=i[p1];
			}
			p2[p1+1]=p2[0];
			i[p1+1]=i[0];
			i[0]++;
		}
		for (p1=1;p1<i[0];p1++) {
			cout<<i[p1];
			if (i[0]-p1!=1) cout<<" ";
		}
		if (t!=1) cout<<endl;
		cout<<endl;
	}
}