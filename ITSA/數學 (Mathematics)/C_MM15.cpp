#include <stdio.h>
int main() {int x, y;while (scanf("%d%d",&x,&y)!=EOF) puts((0<=x&&x<=100&&0<=y&&y<=100)?"inside":"outside");}