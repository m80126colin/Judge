/**
 *  @judge ZeroJudge
 *  @id a008
 *  @tag Simple, Simulation, Ad-hoc, Roman number
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
	bool zero,one,thou;
	string n;
	int t,i;
	while (cin>>n) {
		zero=one=thou=0;
		t=n.size();
		for (i=0;i<n.size();i++) {
			if ((n[i]-48)&&zero) {
				cout<<"�s";
				zero=0;
			}
			if (n[i]=='1'&&(n.size()%4!=2||t%4!=2||one)) {
				cout<<"��";
				one=1;
			}
			else if (n[i]=='2') cout<<"�L";
			else if (n[i]=='3') cout<<"��";
			else if (n[i]=='4') cout<<"�v";
			else if (n[i]=='5') cout<<"��";
			else if (n[i]=='6') cout<<"��";
			else if (n[i]=='7') cout<<"�m";
			else if (n[i]=='8') cout<<"��";
			else if (n[i]=='9') cout<<"�h";
			if ((t>4&&t<9)&&(n[i]>'0'&&n[i]<='9')) thou=1;
			if (n[i]=='0') zero=1;
			if (t%4==1) {
				if (t/4==1&&thou) cout<<"�U";
				else if (t/4==2) cout<<"��";
				zero=0;
				one=1;
			}
			else if (n[i]!='0'&&t%4==2) cout<<"�B";
			else if (n[i]!='0'&&t%4==3) cout<<"��";
			else if (n[i]!='0') cout<<"�a";
			t--;
		}
		cout<<endl;
	}
}