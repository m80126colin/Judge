/**
 *  @judge CPE
 *  @id 10700
 *  @tag Hard, LIS nlgn ver
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v[500001];
vector<int> s,c;

int main() {
	int i,j,n,vt;
	for (vt=0;cin>>n;vt++) v[vt]=n;
	vt--;
	s.push_back(v[0]);
	c.push_back(1);
	for (i=1;i<=vt;i++) {
		n=v[i];
		if (n>s.back()) {
			c.push_back(s.size()+1);
			s.push_back(n);
		}
		else {
			c.push_back(lower_bound(s.begin(),s.end(),n)-s.begin()+1);
			*lower_bound(s.begin(),s.end(),n)=n;
		}
	}
	cout<<s.size()<<endl<<"-"<<endl;
	j=s.size();
	s.clear();
	for (i=c.size();i;i--) {
		if (c[i-1]==j) s.push_back(v[i-1]),j--;
	}
	while (!s.empty()) cout<<s.back()<<endl,s.pop_back();
}