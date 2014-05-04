#include <iostream>
using namespace std;

int main() {
	int i;
	while (scanf("%d",&i)!=EOF) cout<<(25-i)+60*(i>25)<<endl;
}