#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string mom,com,s;
	getline(cin,mom);
	while (cin>>com&&com!="END") {
		if (com=="ADD") {
			cin.ignore(1);
			getline(cin,s);
			mom+=s;
		}
		else if (com=="ADH") {
			cin.ignore(1);
			getline(cin,s);
			mom.insert(0,s);
		}
		else if (com=="ERA") {
			cin>>i>>j;
			cin.ignore(1);
			mom.erase(i-1,j-i+1);
		}
		else if (com=="SUB") {
			cin>>i>>j;
			cin.ignore(1);
			mom=mom.substr(i-1,j-i+1);
		}
		else {
			cin>>i;
			cin.ignore(1);
			mom.insert(i-1,"_");
		}
		cout<<mom<<endl;
	}
}