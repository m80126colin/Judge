#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	string a;
	int n,k,o,c,i,j;
	for (cin>>k;k;k--) {
		for (scanf("%d %d:%d %d:%d",&n,&o,&c,&i,&j),o=o*60+c,c=i*60+j;n;n--) {
			cin>>a>>i;
			cin.ignore(1);
			cin>>j;
			i=i*60+j;
			j=o-i+1440*(o-i<0);
			i=c-i+1440*(c-i<0);
			cout<<setfill('0')<<setw(2)<<j/60<<":"<<setw(2)<<j%60<<" "<<setw(2)<<i/60<<":"<<setw(2)<<i%60<<endl;
		}
	}
}