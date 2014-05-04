#include <iostream>
using namespace std;

int main() {
	unsigned int k[48];
	k[1]=k[2]=1;
	for (k[0]=3;k[0]<48;k[0]++) k[k[0]]=k[k[0]-1]+k[k[0]-2];
	while (scanf("%u",&k[0])!=EOF) printf("%u\n",k[k[0]]);
}