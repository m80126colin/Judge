#include <stdio.h>
int p[4000],pr;
int output(int sum,int i) {
	int power;
	if (i==pr || p[i]>sum) return 0;
	for (power=0;sum%p[i]==0;sum/=p[i]) power++;
	if (output(sum,i+1)&&power) putchar(' ');
	if (power) {
		printf("%d %d",p[i],power);
	}
	return 1;
}
int main() {
	int i,j,sum,num,power;
	int ox[32768]={0};
	char ch;
	pr=0;
	for (i=2;i<256;i++) {
		if (!ox[i]) {
			p[pr++]=i;
			for (j=2;i*j<32768;j++) ox[i*j]=1;
		}
	}
	for (sum=1;i<32768;i++) if (!ox[i]) p[pr++]=i;
	while (scanf("%d%c",&num,&ch),num) {
		for (scanf("%d%c",&power,&ch);power;power--) sum*=num;
		if (ch=='\n') {
			sum--;
			output(sum,0);
			puts("");
			sum=1;
		}
	}
}