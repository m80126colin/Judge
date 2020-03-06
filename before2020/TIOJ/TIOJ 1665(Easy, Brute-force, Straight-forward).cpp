/**
 *  @judge TIOJ
 *  @id 1665
 *  @tag Easy, Brute force, Straight forward
 */
#include <iostream>
using namespace std;

int main()
{
	int d, t;
	while (scanf("%d", &d) != EOF)
	{
		for (t = 0; d; d /= 10) t++;
		printf("%d\n", t);
	}
}