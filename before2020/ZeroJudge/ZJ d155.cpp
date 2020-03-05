#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string m,n;
	i=j=0;
	while (cin>>m>>n&&(m+" "+n)!="Game Over") {
		if ((m=="Stone"&&n=="Scissors")||(m=="Scissors"&&n=="Paper")||(m=="Paper"&&n=="Stone")) i++,printf("紫獲勝\n");
		if ((n=="Stone"&&m=="Scissors")||(n=="Scissors"&&m=="Paper")||(n=="Paper"&&m=="Stone")) j++,printf("靈夢獲勝\n");
	}
	if (i>j) printf("螢火的蹤跡\n");
	else printf("悲慘的籌措起香油錢\n");
}