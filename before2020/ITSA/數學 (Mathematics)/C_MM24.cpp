#include <stdio.h>
int main() {
	int w,h;
	double ans;
	while (scanf("%d%d",&w,&h)!=EOF) {
		ans = 0;
		if (w <= 60) ans += w * h;
		else {
			ans += 60 * h;
			if (w <= 120) ans += (w - 60) * h * 1.33;
			else ans += 79.8 * h + (w - 120) * h * 1.66;
		}
		printf("%.1lf\n", ans);
	}
}