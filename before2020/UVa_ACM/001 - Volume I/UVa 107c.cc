#include <stdio.h>
#include <math.h>
int main() {
	int h,n,i,j,k,sum1,sum2;
	while (scanf("%d%d",&h,&n),h||n) {
		if (h==1) {
			printf("0 1\n");
			continue;
		}
		for (i=1;pow((double)h,(double)1/i)>1;i++) {
			j=pow((double)h,(double)1/i)+0.1;
			if ((int) (pow((double)j,i)+0.1)==h && (int) (pow((double)j-1,i)+0.1)==n) 
				break;
		}
		sum1=sum2=0;
		for (k=0;k<=i;k++) {
			if (k!=i) sum1+=(int) (pow((double)j-1,k)+0.1);
			sum2+=(int) (pow((double)j,i-k)+0.1) * (int) (pow((double)j-1,k)+0.1);
		}
		printf("%d %d\n",sum1,sum2);
	}
}