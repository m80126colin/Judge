#include <stdio.h>
int i;
int hanoi(int source,int another,int goal,int n) {
	if (n==1) return printf("#%d : move the dish from #%d to #%d\n",i++,source,goal);
	hanoi(source,goal,another,n-1);
	hanoi(source,another,goal,1);
	hanoi(another,source,goal,n-1);
	return 0;
}
int main() {
	int n;
	scanf("%d",&n);
	i=1;
	hanoi(1,2,3,n);
}