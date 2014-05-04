/*
ID: m80126c2
PROG: milk3
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream cin("milk3.in");
ofstream cout("milk3.out");

bool dp[21][21][21],pos[21];

struct Jug{
	int a,b,c;
}jug,queue[10000];

istream& operator >> (istream& is,Jug& x) {
	is>>x.a>>x.b>>x.c;
	return is;
}

Jug in(const int& x,const int& y,const int& z) {
	Jug app;
	app.a=x,app.b=y,app.c=z;
	return app;
}

int main() {
	int i,j;
	cin>>jug;
	for (i=0;i<=jug.a;i++) {
		for (j=0;j<=jug.b;j++) {
			for (int k=0;k<=jug.c;k++) dp[i][j][k]=0;
		}
	}
	for (i=0;i<=jug.c;i++) pos[i]=0;
	queue[1]=in(0,0,jug.c);
	for (i=j=1;j<=i;j++) {
		if (!dp[queue[j].a][queue[j].b][queue[j].c]) {
			dp[queue[j].a][queue[j].b][queue[j].c]=1;
			if (queue[j].a) {
				if (queue[j].a>jug.b-queue[j].b) queue[i+1]=in(queue[j].a+queue[j].b-jug.b,jug.b,queue[j].c),i++; //a->b
				else queue[i+1]=in(0,queue[j].b+queue[j].a,queue[j].c),i++;
				if (queue[j].a>jug.c-queue[j].c) queue[i+1]=in(queue[j].a+queue[j].c-jug.c,queue[j].b,jug.c),i++; //a->c
				else queue[i+1]=in(0,queue[j].b,queue[j].c+queue[j].a),i++;
			}
			if (queue[j].b) {
				if (queue[j].b>jug.a-queue[j].a) queue[i+1]=in(jug.a,queue[j].b+queue[j].a-jug.a,queue[j].c),i++; //b->a
				else queue[i+1]=in(queue[j].a+queue[j].b,0,queue[j].c),i++;
				if (queue[j].b>jug.c-queue[j].c) queue[i+1]=in(queue[j].a,queue[j].b+queue[j].c-jug.c,jug.c),i++; //b->c
				else queue[i+1]=in(queue[j].a,0,queue[j].c+queue[j].b),i++;
			}
			if (queue[j].c) {
				if (queue[j].c>jug.a-queue[j].a) queue[i+1]=in(jug.a,queue[j].b,queue[j].c+queue[j].a-jug.a),i++; //c->a
				else queue[i+1]=in(queue[j].a+queue[j].c,queue[j].b,0),i++;
				if (queue[j].c>jug.b-queue[j].b) queue[i+1]=in(queue[j].a,jug.b,queue[j].c+queue[j].b-jug.b),i++; //c->b
				else queue[i+1]=in(queue[j].a,queue[j].c+queue[j].b,0),i++;
			}
		}
	}
	for (i=0;i<=jug.b;i++) {
		for (j=0;j<=jug.c;j++) {
			if (dp[0][i][j]) pos[j]=1;
		}
	}
	bool ox=0;
	for (i=0;i<=jug.c;i++) {
		if (pos[i]) {
			if (ox) cout<<" ";
			cout<<i;
			ox=1;
		}
	}
	cout<<endl;
}