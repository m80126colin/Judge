#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string m,n;
	i=j=0;
	while (cin>>m>>n&&(m+" "+n)!="Game Over") {
		if ((m=="Stone"&&n=="Scissors")||(m=="Scissors"&&n=="Paper")||(m=="Paper"&&n=="Stone")) i++,printf("�����\n");
		if ((n=="Stone"&&m=="Scissors")||(n=="Scissors"&&m=="Paper")||(n=="Paper"&&m=="Stone")) j++,printf("�F�����\n");
	}
	if (i>j) printf("�ä����ܸ�\n");
	else printf("�d�G���w���_���o��\n");
}