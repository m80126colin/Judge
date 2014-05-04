#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	int i,s,t,j[14];
	string n;
	while (getline(cin,n)) {
		ox=1;
		s=0;
		t=1;
		memset(j,0,sizeof(j));
		for (i=0;i<n.size();i++) {
			if (n.substr(i,1)=="M") {
				if (t>1) {
					ox=0;
					break;
				}
				t=1;
				j[t]++;
				s+=1000;
				continue;
			}
			if (n.substr(i,2)=="CM") {
				if (t>2) {
					ox=0;
					break;
				}
				t=2;
				j[t]++;
				s+=900;
				i++;
				continue;
			}
			if (n.substr(i,1)=="D") {
				if (t>3) {
					ox=0;
					break;
				}
				t=3;
				j[t]++;
				s+=500;
				continue;
			}
			if (n.substr(i,2)=="CD") {
				if (t>4) {
					ox=0;
					break;
				}
				t=4;
				j[t]++;
				s+=400;
				i++;
				continue;
			}
			if (n.substr(i,1)=="C") {
				if (t>5) {
					ox=0;
					break;
				}
				t=5;
				j[t]++;
				s+=100;
				continue;
			}
			if (n.substr(i,2)=="XC") {
				if (t>6) {
					ox=0;
					break;
				}
				t=6;
				j[t]++;
				s+=90;
				i++;
				continue;
			}
			if (n.substr(i,1)=="L") {
				if (t>7) {
					ox=0;
					break;
				}
				t=7;
				j[t]++;
				s+=50;
				continue;
			}
			if (n.substr(i,2)=="XL") {
				if (t>8) {
					ox=0;
					break;
				}
				t=8;
				j[t]++;
				s+=40;
				i++;
				continue;
			}
			if (n.substr(i,1)=="X") {
				if (t>9) {
					ox=0;
					break;
				}
				t=9;
				j[t]++;
				s+=10;
				continue;
			}
			if (n.substr(i,2)=="IX") {
				if (t>10) {
					ox=0;
					break;
				}
				t=10;
				j[t]++;
				s+=9;
				i++;
				continue;
			}
			if (n.substr(i,1)=="V") {
				if (t>11) {
					ox=0;
					break;
				}
				t=11;
				j[t]++;
				s+=5;
				continue;
			}
			if (n.substr(i,2)=="IV") {
				if (t>12) {
					ox=0;
					break;
				}
				t=12;
				j[t]++;
				s+=4;
				i++;
				continue;
			}
			if (n.substr(i,1)=="I") {
				if (t>13) {
					ox=0;
					break;
				}
				t=13;
				j[t]++;
				s+=1;
				continue;
			}
		}
		for (i=1;i<=13;i++) {
			if ((i%2&&i%4==1&&j[i]>=4)||(i%2&&i>1&&i%4==3&&j[i]>1)||(!(i%2)&&j[i]>1)) {
				ox=0;
				break;
			}
		}
		for (i=2;i<13;i+=4) {
			if ((j[i]&&j[i+1])||(j[i+1]&&j[i+2])||(j[i+2]&&j[i+3])||(j[i]&&j[i+2])||(j[i]&&j[i+3])) {
				ox=0;
				break;
			}
		}
		if (ox) cout<<s<<endl;
		else cout<<"This is not a valid number\n";
	}
}