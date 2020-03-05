#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int i,j,a,b;
	double n[1000];
	while (cin>>j&&j) {
		for (i=1;i<=j;i++) {
			scanf("%d %d",&a,&b);
			n[i]=a+b+0.5+0.25*((a>b)-(a<b));
		}
		sort(n+1,n+j+1);
		for (i=j;i;i--) {
			if (i!=j) cout<<" ";
			a=n[i];
			if (n[i]>a+0.5) cout<<">";
			else if (n[i]<a+0.5) cout<<"<";
			else cout<<"=";
			cout<<a;
		}
		cout<<endl;
	}
}