/*
ID: m80126c2
PROB: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("milk2.in");
ofstream fout ("milk2.out");

bool ox[1000001];

int main() {
	int n,i,a,b,x,y;
	x=1000000,y=0;
	for (fin>>n;n;n--) {
		fin>>a>>b;
		for (i=a;i<b;i++) ox[i]=1;
		if (a<x) x=a;
		if (b>y) y=b;
	}
	a=b=0;
	for (i=n=x;i<y;i++) {
		if (ox[i]!=ox[i+1]) {
			if (ox[i]) a=max(a,i+1-n);
			else b=max(b,i+1-n);
			n=i+1;
		}
	}
	fout<<a<<" "<<b<<endl;
}