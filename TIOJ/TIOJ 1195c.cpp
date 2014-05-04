#include <stdio.h>
int main() {
	int n,i,sum=0;
	char s[10];
	for (scanf("%d",&n),i=1;i<=n;i++) {
		scanf("%s",&s);
		if (s[5]==s[4]&&s[4]==s[3]&&s[3]==s[2]) sum+=2000;
		else if ((s[5]==s[4]&&s[4]==s[3])||(s[4]==s[3]&&s[3]==s[2])) sum+=1000;
		else if (s[5]==s[4]&&s[3]==s[2]) sum+=1500;
	}
	printf("%d\n",sum);
}