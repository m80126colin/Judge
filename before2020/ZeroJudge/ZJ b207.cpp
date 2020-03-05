#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct ball{
	char ch;
	string n;
	int s;
	int g;
	int l;
};

bool cmp(ball x,ball y) {
	if (x.ch!=y.ch) return x.ch<y.ch;
	else if (x.s!=y.s) return x.s>y.s;
	else if (x.g!=y.g) return x.g>y.g;
	else if (x.l!=y.l) return x.l<y.l;
	return x.n<y.n;
}

int main() {
	string m,n;
	int n1,i,j,k,x,y;
	ball a[8];
	for (cin>>n1;n1;n1--) {
		for (i=0;i<8;i++) {
			a[i].s=a[i].g=a[i].l=0;
			if (i<4) a[i].ch='A';
			else a[i].ch='B';
			cin>>a[i].n;
		}
		for (i=1;i<=12;i++) {
			cin>>m>>x>>y>>n;
			for (j=0;j<8;j++) if (a[j].n==m) break;
			for (k=0;k<8;k++) if (a[k].n==n) break;
			if (x==y) a[j].s++,a[k].s++;
			else a[j*(x>y)+k*(x<y)].s+=3;
			a[j].g+=x,a[j].l+=y;
			a[k].g+=y,a[k].l+=x;
		}
		sort(a,a+8,cmp);
		cout<<"A1 "<<a[0].n<<endl;
		cout<<"A2 "<<a[1].n<<endl;
		cout<<"B1 "<<a[4].n<<endl;
		cout<<"B2 "<<a[5].n<<endl;
		cout<<"BEST3 ";
		if (a[2].s!=a[6].s) {
			if (a[2].s>a[6].s) cout<<a[2].n;
			else cout<<a[6].n;
		}
		else if (a[2].g!=a[6].g) {
			if (a[2].g>a[6].g) cout<<a[2].n;
			else cout<<a[6].n;
		}
		else if (a[2].l!=a[6].l) {
			if (a[2].l<a[6].l) cout<<a[2].n;
			else cout<<a[6].n;
		}
		else {
			if (a[2].n<a[6].n) cout<<a[2].n;
			else cout<<a[6].n;
		}
		cout<<endl;
	}
}