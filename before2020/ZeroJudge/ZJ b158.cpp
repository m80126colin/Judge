#include <iostream>
#include <algorithm>
using namespace std;

struct scr{
	int n;
	int a;
	int b;
	int c;
};

bool cmp(scr x,scr y) {
	if ((x.a+x.b+x.c)==(y.a+y.b+y.c)) {
		if (x.a==y.a) return x.n<y.n;
		else return x.a>y.a;
	}
	else return (x.a+x.b+x.c)>(y.a+y.b+y.c);
}

int main() {
	bool ox;
	int i,n;
	scr stu[301];
	ox=0;
	while (cin>>n) {
		for (i=1;i<=n;i++) {
			stu[i].n=i;
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
		}
		sort(stu+1,stu+n+1,cmp);
		if (ox) cout<<endl;
		for (i=1;i<=5;i++) cout<<stu[i].n<<" "<<stu[i].a+stu[i].b+stu[i].c<<endl;
		ox=1;
	}
}