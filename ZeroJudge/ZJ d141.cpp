#include <iostream>
using namespace std;

int main() {
	int x1,y1,x2,y2,x3,y3,n;
	for (cin>>n;n;n--) {
		scanf("%d,%d %d,%d %d,%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if ((x1-x2)*(y2-y3)==(x2-x3)*(y1-y2)) printf("collinear\n");
		else printf("not collinear\n");
	}
}