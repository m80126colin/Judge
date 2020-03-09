/**
 *  @judge ZeroJudge
 *  @id d143
 *  @source UVa 11172
 * 
 *  @tag Easy, Comparison operator
 */
#include <iostream>
using namespace std;

int main() {
	int a,b,n;
	for (scanf("%d",&n);n;n--) {
		scanf("%d %d",&a,&b);
		if (a==b) printf("=\n");
		else if (a>b) printf(">\n");
		else printf("<\n");
	}
}