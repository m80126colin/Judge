#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> v;
int map[200][200];

int find_string(string x) {
	int i,j=-1;
	for (i=0;i<v.size();i++) {
		if (v[i]==x) j=i;
	}
	return j;
}

void floyd() {
	int i,j,k;
	for (i=0;i<v.size();i++) 
		for (j=0;j<v.size();j++) 
			for (k=0;k<v.size();k++)
				map[i][j]=max(map[i][j],min(map[i][k],map[k][j]));
}

int main() {
	int n,r,c,i,j,ctr;
	string s,t;
	for (ctr=1;cin>>n>>r,n||r;ctr++) {
		v.clear();
		memset(map,0,sizeof(map));
		for (i=1;i<=r;i++) {
			int k,l;
			cin>>s>>t>>c;
			k=find_string(s);
			if (k==-1) v.push_back(s),k=v.size()-1;
			l=find_string(t);
			if (l==-1) v.push_back(t),l=v.size()-1;
			map[k][l]=map[l][k]=c;
		}
		floyd();
		cin>>s>>t;
		i=find_string(s),j=find_string(t);
		cout<<"Scenario #"<<ctr<<endl<<map[i][j]<<" tons\n\n";
	}
}