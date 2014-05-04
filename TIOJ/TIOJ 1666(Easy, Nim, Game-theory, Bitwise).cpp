#include <stdio.h>
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) puts((a^b)?"kelvin":"yiping");
}