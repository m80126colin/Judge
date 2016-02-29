#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,m,i,j,s;
	bool point[101];
	vector <int> list[101];
	while (cin>>n>>m,n||m) {
		for (i=1;i<=n;i++) {
			list[i].clear();
			point[i]=1;
		}
		for (i=1;i<=m;i++) {
			int k;
			cin>>j>>k;
			list[k].push_back(j);
		}
		for (i=1;i<=n;i++) {
			s=1;
			while (s<=n&&((!list[s].empty()&&point[s])||(!point[s]))) s++;
			if (s==n+1) break;
			point[s]=0;
			cout<<s;
			if (i<n) cout<<" ";
			for (j=1;j<=n;j++) {
				for (vector<int>::size_type k=0;k<list[j].size();k++) {
					if (list[j][k]==s) {
						vector<int>::iterator iter=list[j].begin()+k;
						list[j].erase(iter);
						break;
					}
				}
			}
		}
		cout<<endl;
	}
}