#include <iostream>
using namespace std;

int main() {
	unsigned long long n,up[52],lt_rt[52];
	for (n=2,up[1]=1,lt_rt[1]=0;n<=51;n++) {
		up[0]=lt_rt[n-1];
		lt_rt[0]=up[n-1]*2;
		up[n]=up[0]+up[n-1];
		lt_rt[n]=lt_rt[0]+lt_rt[n-1];
	}
	cin>>n;
	cout<<up[n+1]+lt_rt[n+1]<<endl;
}