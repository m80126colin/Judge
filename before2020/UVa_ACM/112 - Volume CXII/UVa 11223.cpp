#include <iostream>
#include <string>
using namespace std;

string n,g;
int t,d,s;

int alpha(string x) {
	if (x==".-") cout<<"A";
	if (x=="-...") cout<<"B";
	if (x=="-.-.") cout<<"C";
	if (x=="-..") cout<<"D";
	if (x==".") cout<<"E";
	if (x=="..-.") cout<<"F";
	if (x=="--.") cout<<"G";
	if (x=="....") cout<<"H";
	if (x=="..") cout<<"I";
	if (x==".---") cout<<"J";
	if (x=="-.-") cout<<"K";
	if (x==".-..") cout<<"L";
	if (x=="--") cout<<"M";
	if (x=="-.") cout<<"N";
	if (x=="---") cout<<"O";
	if (x==".--.") cout<<"P";
	if (x=="--.-") cout<<"Q";
	if (x==".-.") cout<<"R";
	if (x=="...") cout<<"S";
	if (x=="-") cout<<"T";
	if (x=="..-") cout<<"U";
	if (x=="...-") cout<<"V";
	if (x==".--") cout<<"W";
	if (x=="-..-") cout<<"X";
	if (x=="-.--") cout<<"Y";
	if (x=="--..") cout<<"Z";
	if (x=="-----") cout<<"0";
	if (x==".----") cout<<"1";
	if (x=="..---") cout<<"2";
	if (x=="...--") cout<<"3";
	if (x=="....-") cout<<"4";
	if (x==".....") cout<<"5";
	if (x=="-....") cout<<"6";
	if (x=="--...") cout<<"7";
	if (x=="---..") cout<<"8";
	if (x=="----.") cout<<"9";
	if (x==".-.-.-") cout<<".";
	if (x=="--..--") cout<<",";
	if (x=="..--..") cout<<"?";
	if (x==".----.") cout<<"\'";
	if (x=="-.-.--") cout<<"!";
	if (x=="-..-.") cout<<"/";
	if (x=="-.--.") cout<<"(";
	if (x=="-.--.-") cout<<")";
	if (x==".-...") cout<<"&";
	if (x=="---...") cout<<":";
	if (x=="-.-.-.") cout<<";";
	if (x=="-...-") cout<<"=";
	if (x==".-.-.") cout<<"+";
	if (x=="-....-") cout<<"-";
	if (x=="..--.-") cout<<"_";
	if (x==".-..-.") cout<<"\"";
	if (x==".--.-.") cout<<"@";
	g="";
	return 0;
}

int main() {
	d=1;
	for (cin>>t;d<=t;d++) {
		cout<<"Message #"<<d<<endl;
		g="";
		if (d==1) cin.ignore(1);
		getline(cin,n);
		for (s=0;s<n.size();s++) {
			if (n[s]==' ') alpha(g);
			else g+=n[s];
			if (n[s]==' '&&n[s+1]==' ') cout<<" ";
		}
		alpha(g);
		cout<<endl;
		if (d!=t) cout<<endl;
	}
}