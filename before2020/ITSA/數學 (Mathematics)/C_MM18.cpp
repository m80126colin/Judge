#include <stdio.h>
int main(){int i;char c;while (scanf("%d",&i)!=EOF) {for (c=i,i=7;i>=0;i--)putchar((c&(1<<i))?'1':'0');puts("");}}