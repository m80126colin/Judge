#include <stdio.h>
int main() {
	int a,h1,h2,ans;
	scanf("%d%d",&a,&h1);
	h1+=a*60;
	scanf("%d%d",&a,&h2);
	h2+=a*60;
	h2-=h1;
	if (h2 < 0) h2+=1440;
	ans = 0;
	if (h2 <= 120) ans += h2/30*30;
	else {
		ans += 120;
		if (h2 <= 240) ans = (h2-120)/30*40;
		else ans += 160 + (h2-240)/30*60;
	}
	printf("%d\n",ans);
}