#include <iostream>
using namespace std;

int main() {
	int n,x1,y1,x2,y2,x3,y3;
	for (cin>>n;n;n--) {
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		if ((x1-x2)*(y2-y3)==(x2-x3)*(y1-y2)&&(x3-x1)*(x3-x2)<=0&&(y3-y1)*(y3-y2)<=0) cout<<"�Ӧ����F��!�����Q���ڦ��I\n";
		else cout<<"���ˤj�H!���ˤj�H!�ڧ֨�F�I\n";
	}
}