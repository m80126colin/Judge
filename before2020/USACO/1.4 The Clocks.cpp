/*
ID: m80126c2
PROG: clocks
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <queue>
#define MAX 262144
using namespace std;

ifstream cin("clocks.in");
ofstream cout("clocks.out");

queue<int> q;
bool ox[MAX];
int root[MAX],step[MAX],traversal[10];
int cc[9][9]={
	{4,0,2,6,8},
	{3,0,2,4},
	{4,2,4,8,10},
	{3,0,6,12},
	{5,2,6,8,10,14},
	{3,4,10,16},
	{4,6,8,12,14},
	{3,12,14,16},
	{4,8,10,14,16}
};

int main() {
	int i,j,tmp;
	tmp=0;
	for (i=0;i<9;i++) {
		cin>>j;
		tmp |=( ((j/3)%4) << (2*i) );
	}
	root[tmp]=tmp;
	step[tmp]=0;
	ox[tmp]=1;
	for (q.push(tmp);!q.empty();) {
		if (ox[0]) break;
		for (i=0;i<9;i++) {
			tmp=q.front();
			for (j=1;j<=cc[i][0];j++) {
				int k=( ((( (tmp&(3<<cc[i][j])) >> cc[i][j] )+1)%4) << cc[i][j] );
				tmp=~tmp;
				tmp|=(3<<cc[i][j]);
				tmp=~tmp;
				tmp|=k;
			}
			if (!ox[tmp]) {
				ox[tmp]=1;
				root[tmp]=q.front();
				step[tmp]=i+1;
				q.push(tmp);
			}
		}
		q.pop();
	}
	memset(traversal,0,sizeof(traversal));
	for (i=0;i!=root[i];i=root[i]) traversal[step[i]]++;
	bool d=0;
	for (i=1;i<=9;i++) {
		for (j=1;j<=traversal[i];j++) {
			if (d) cout<<" ";
			cout<<i;
			d=1;
		}
	}
	cout<<endl;
}