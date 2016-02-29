#include <iostream>
#include <string>
using namespace std;

int s,i,j;
string n;

int aa() {
	int x;
	for (x=s;x;x--) cout<<"-";
	return 0;
}

int bb() {
	int x;
	for (x=s;x;x--) cout<<" ";
	return 0;
}

int cc() {
	cout<<"|";
	return 0;
}

int dd(int x) {
	if (x<n.size()-1) cout<<" ";
	return 0;
}

int main() {
	while (cin>>s>>n&&s) {
		for (i=0;i<n.size();i++) {
			cout<<" ";
			if (n[i]=='0'||n[i]=='2'||n[i]=='3'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9') aa();
			else bb();
			cout<<" ";
			dd(i);
		}
		cout<<endl;
		for (j=s;j;j--) {
			for (i=0;i<n.size();i++) {
				if (n[i]=='0'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='8'||n[i]=='9') cc();
				else cout<<" ";
				bb();
				if (n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='7'||n[i]=='8'||n[i]=='9') cc();
				else cout<<" ";
				dd(i);
			}
			cout<<endl;
		}
		for (i=0;i<n.size();i++) {
			cout<<" ";
			if (n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='8'||n[i]=='9') aa();
			else bb();
			cout<<" ";
			dd(i);
		}
		cout<<endl;
		for (j=s;j;j--) {
			for (i=0;i<n.size();i++) {
				if (n[i]=='0'||n[i]=='2'||n[i]=='6'||n[i]=='8') cc();
				else cout<<" ";
				bb();
				if (n[i]=='0'||n[i]=='1'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9') cc();
				else cout<<" ";
				dd(i);
			}
			cout<<endl;
		}
		for (i=0;i<n.size();i++) {
			cout<<" ";
			if (n[i]=='0'||n[i]=='2'||n[i]=='3'||n[i]=='5'||n[i]=='6'||n[i]=='8'||n[i]=='9') aa();
			else bb();
			cout<<" ";
			dd(i);
		}
		cout<<endl<<endl;
	}
}