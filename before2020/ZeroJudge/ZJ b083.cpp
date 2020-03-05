#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct ball{
	string n;
	int a;
	int b;
	double c;
};

bool cmp(ball x,ball y) {
	if (x.a!=y.a) return x.a>y.a;
	else if (x.b!=y.b) return x.b<y.b;
	return x.c<y.c;
}

bool cmb(ball x,ball y) {
	if (x.a!=y.a) return x.a>y.a;
	else if (x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}

int main() {
	char ch;
	int k,n,i,j,a;
	ball p[1001],b[1001];
	for (cin>>k,a=1;a<=k;a++) {
		i=j=1;
		for (cin>>n;n;n--) {
			cin>>ch;
			if (ch=='P') cin>>p[i].n>>p[i].a>>p[i].b>>p[i].c,i++;
			else cin>>b[j].n>>b[j].a>>b[j].b>>b[j].c,j++;
		}
		sort(p+1,p+i,cmp),sort(b+1,b+j,cmb);
		for (n=1;n<i;n++) cout<<"P "<<p[n].n<<endl;
		for (n=1;n<j;n++) cout<<"B "<<b[n].n<<endl;
		if (a!=k) cout<<"=====\n";
	}
}