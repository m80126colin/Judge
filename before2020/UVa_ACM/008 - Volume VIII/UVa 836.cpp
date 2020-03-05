#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,i,j,t,sum,maxn,map[101][101];
	string s[101];
	for (cin>>n;n;n--) {
		memset(map,0,sizeof(map));
		for (cin>>s[1],i=2;i<=s[1].size();i++) cin>>s[i];
		maxn=t=sum=0;
		for (i=1;i<=s[1].size();i++) {
			for (j=1;j<=s[1].size();j++) {
				if (s[i][j-1]=='1') {
					map[i][j]=map[i-1][j]+1;
					if (!t) t=map[i][j];
					else t=min(t,map[i][j]);
					if (map[i][j]>=t) sum++;
					if (sum*t>maxn) maxn=sum*t;
				}
				else t=sum=0;
			}
			t=sum=0;
		}
		cout<<maxn<<endl;
		if (n>1) cout<<endl;
	}
}