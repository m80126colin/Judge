#include <iostream>
#include <algorithm>
#define MAX 2304
using namespace std;

struct rect{
	int p,q,ar;
}r1[MAX],r2[4];
int j,dp[4];

inline combric(const rect& x,const rect& y) {
	rect z;
	z.p=x.p+y.p;
	z.q=max(x.q,y.q);
	if (z.p>z.q) swap(z.p,z.q);
	return z;
}

void com1(const int& x,const int& y,const int& z) {
	if (z==3) {
		r1[j].p=x,r1[j].q=y;
		if (r1[j].p>r1[j].q) swap(r1[j].p,r1[j].q);
		r1[j].ar=r1[j].p*r1[j].q;
		j++;
		return;
	}
	com1(x+r2[z+1].p,max(y,r2[z+1].q),z+1);
	com1(x+r2[z+1].q,max(y,r2[z+1].p),z+1);
	return;
}

void com2(const int& x,const int& y,const int& z) {
	if (z==3) {
		com1(max(x,r2[dp[0]].p),y+r2[dp[0]].q,3);
		com1(max(x,r2[dp[0]].q),y+r2[dp[0]].p,3);
		return;
	}
	com1(x+r2[dp[z+1]].p,max(y,r2[dp[z+1]].q),z+1);
	com1(x+r2[dp[z+1]].q,max(y,r2[dp[z+1]].p),z+1);
	return;
}

int main() {
	int i;
	for (i=0;i<4;i++) {
		cin>>r2[i].p>>r2[i].q;
		if (r2[i].p>r2[i].q) swap(r2[i].p,r2[i].q);
	}
	j=0;
	com1(r2[0].p,r2[0].q,0);
	com1(r2[0].q,r2[0].p,0);
	for (i=0;i<4;i++) dp[i]=i;
	do {
		com2(r2[dp[1]].p,r2[dp[1]].q,1);
		com2(r2[dp[1]].q,r2[dp[1]].p,1);
	} while (next_permutation(dp));
	for (i=0;i<4;i++) dp[i]=i;
}