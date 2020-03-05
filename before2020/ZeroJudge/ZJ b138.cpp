#include <iostream>
using namespace std;

int main() {
	int i[11],j,n;
	while (cin>>i[1]&&!cin.eof()) {
		for (i[0]=2;i[0]<=10;i[0]++) cin>>i[i[0]];
		cin>>i[0];
		for (n=0,j=1;j<=10;j++) {
			if (i[0]+30>=i[j]) n++;
		}
		cout<<n<<endl;
	}
}