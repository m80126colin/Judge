/**
 *  @judge TIOJ
 *  @id 1666
 *  @tag Easy, Nim, Game theory, Bitwise Operation
 */
#include <stdio.h>
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) puts((a^b)?"kelvin":"yiping");
}