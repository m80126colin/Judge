#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;int a,b;
	while (getline(cin,n)) for (a=b=0;b<n.size();b++) (n[b]+a>168) ? printf("%d %d\n",b,120-a),b+=n.size() : a+=n[b]-48 ;
}