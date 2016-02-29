#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

bool ox[12];
int coin[12];

int main() {
	int n,m,i,j,a,b;
	string s[3];
	for (cin>>n;n;n--) {
		for (i=0;i<12;i++) ox[i]=coin[i]=0;
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) cin>>s[j];
			if (s[2]=="even") {
				for (a=0;a<2;a++) {
					for (b=0;b<s[a].size();b++) coin[s[a][b]-'A']=0,ox[s[a][b]-'A']=1;
				}
			}
			else if (s[2]=="up") {
				for (a=0;a<2;a++) {
					for (b=0;b<s[a].size();b++) {
						if (!ox[s[a][b]-'A']) coin[s[a][b]-'A']+=(a&1)*1+(-1)*(a==0);
					}
				}
			}
			else {
				for (a=0;a<2;a++) {
					for (b=0;b<s[a].size();b++) {
						if (!ox[s[a][b]-'A']) coin[s[a][b]-'A']+=(a&1)*(-1)+1*(a==0);
					}
				}
			}
		}
		m=0;
		for (i=0;i<12;i++) {
			if (abs(coin[i])>m) m=abs(coin[i]);
			else ox[i]=1;
		}
		for (i=0;i<12;i++) {
			if (m==abs(coin[i])&&!ox[i]) cout<<(char) (i+'A') <<" is the counterfeit coin and it is "<<((coin[i]>0) ? "light" : "heavy")<<".\n";
		}
	}
}