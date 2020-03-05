#include <stdio.h>
int main(){int a;while (scanf("%d",&a)!=EOF){(a<31)?printf("%d\n",1<<a):puts("Value of more than 31");}}