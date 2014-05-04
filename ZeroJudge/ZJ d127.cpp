#include <iostream>
using namespace std;

int main() {
	long long l;
	while (scanf("%lld",&l)!=EOF) printf("%lld\n",((l/2+1)/2)*((l/2)/2));
}