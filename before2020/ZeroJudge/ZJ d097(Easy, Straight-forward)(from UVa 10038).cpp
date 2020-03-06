/**
 *  @judge ZeroJudge
 *  @id d097
 *  @tag Easy, Straight forward
 */
#include <iostream>
using namespace std;

int main() {
	bool ox;
	int n,a,b,i,x[3000];
	while (cin>>n) {
		ox=1;
		memset(x,0,sizeof(x));
		cin>>a;
		for (i=2;i<=n;i++,a=b) {
			cin>>b;
			x[abs(a-b)]++;
		}
		for (i=1;i<n;i++) { 
			if (x[i]>1||x[i]==0) {
				ox=0;
				break;
			}
		}
		cout<<( (ox) ? "Jolly" : "Not jolly" )<<endl;
	}
}