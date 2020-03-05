#include <iostream>
#include <string>
using namespace std;

int in[26],out[26],map[26][26],st,ed;
int visit[26];
bool ox;

void dfs(int x) {
	int i;
	for (i=0;i<26;i++) {
		if (map[x][i]&&visit[i]<in[i]) {
			visit[i]++;
			dfs(i);
		}
	}
}

int main() {
	string s;
	int t,n,i,j;
	for (cin>>t;t;t--) {
		for (i=0;i<26;i++) {
			for (j=0;j<26;j++) map[i][j]=0;
			visit[i]=in[i]=out[i]=0;
		}
		st=ed=ox=0;
		for (cin>>n;n;n--) {
			cin>>s;
			map[s[0]-'a'][s[s.size()-1]-'a']++;
		}
		for (i=0;i<26;i++) {
			for (j=0;j<26;j++) {
				out[i]+=map[i][j];
				in[j]+=map[i][j];
			}
		}
		for (i=0;i<26;i++) {
			if (out[i]==in[i]) continue;
			else if (out[i]==in[i]+1&&!st) st=i;
			else if (out[i]+1==in[i]&&!ed) ed=i;
			else ox=1;
		}
		dfs(st);
		for (i=0;i<26;i++) {
			if (visit[i]!=in[i]) ox=1;
		}
		if (ox) cout<<"The door cannot be opened.\n";
		else cout<<"Ordering is possible.\n";
	}
}