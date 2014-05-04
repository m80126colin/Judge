#include <stdio.h>
int main() {int x, y;while (scanf("%d%d",&x,&y)!=EOF) puts((x*x+y*y<=10000)?"inside":"outside");}