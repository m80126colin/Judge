#include <iostream>
#include <algorithm>
using namespace std;

long long a;
int n[5843],t,i;

int re(long long x) {
	int j;
	if (x>2000000000) return 0;
	for (j=1;j<=t;j++) {
		if (x==n[j]) return 0;
	}
	n[t+1]=x;
	t++;
}

int main() {
	n[1]=t=1;
	for (i=1;i<=t&&t<=5842;i++) {
		re((long long) n[i]*2);
		re((long long) n[i]*3);
		re((long long) n[i]*5);
		re((long long) n[i]*7);
	}
	sort(n+1,n+5843);
	while (cin>>t&&t) {
		cout<<"The "<<t;
		if (t%10==1&&t%100!=11) cout<<"st";
		else if (t%10==2&&t%100!=12) cout<<"nd";
		else if (t%10==3&&t%100!=13) cout<<"rd";
		else cout<<"th";
		cout<<" humble number is "<<n[t]<<".\n";
	}
}