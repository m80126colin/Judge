#include <stdio.h>
#define MAX 10500
int main() {
	int pr[1300],npr,ox[MAX]={0},dp[10002];
	int i,j,a,b,test,ox2;
	npr=0,ox[0]=ox[1]=1;
	for (i=1;i<MAX;i++) {
		if (!ox[i]) {
			pr[npr++]=i;
			for (j=2;i*j<MAX;j++) ox[i*j]=1;
		}
	}
	dp[0]=0;
	for (i=0;i<=10000;i++) {
		dp[i+1]=dp[i];
		test=i*(i+1)+41;
		ox2=1;
		for (j=0;j<npr && pr[j]<test && ox2;j++) {
			if (!(test%pr[j])) ox2=0;
		}
		if (ox2) dp[i+1]++;
	}
	while (scanf("%d%d",&a,&b)!=EOF) {
		test=(dp[b+1]-dp[a])*100000/(b-a+1);
		if (test%10>=5) test+=10;
		printf("%d.%02d\n",test/1000,test%1000/10);
	}
}