#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int i,j,t;
	while (getline(cin,n)&&n!="e/o/i") {
		n+=" ";
		j=1;
		for (i=t=0;i<n.size()-1;i++) {
			if (n[i]=='a'||n[i]=='e'||n[i]=='i'||n[i]=='o'||n[i]=='u'||n[i]=='y') {
				t++;
				if (n[i+1]=='a'||n[i+1]=='e'||n[i+1]=='i'||n[i+1]=='o'||n[i+1]=='u'||n[i+1]=='y') {
					while (n[i+1]=='a'||n[i+1]=='e'||n[i+1]=='i'||n[i+1]=='o'||n[i+1]=='u'||n[i+1]=='y') i++;
				}
			}
			if (n[i]=='/') {
				if ((j==1&&t!=5)||(j==2&&t!=7)||(j==3&&t!=5)) break;
				j++;
				t=0;
			}
		}
		if (j==3&&t==5) cout<<"Y"<<endl;
		if (j<3||(j==3&&t!=5)) cout<<j<<endl;
	}
}