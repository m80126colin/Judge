#include <iostream>
using namespace std;

int main() {
	bool h;
	int n,t,p_x,p_y,x,y,v_x,v_y;
	while (cin>>n>>t>>p_x>>p_y&&n) {
		h=1;
		for (n;n;n--) {
			cin>>x>>y>>v_x>>v_y;
			if ((p_x-x)*v_y==(p_y-y)*v_x&&v_x*(p_x-x)>=0&&v_y*(p_y-y)>=0&&abs(v_x*t)>=abs(p_x-x)&&abs(v_y*t)>=abs(p_y-y)) h=0;
		}
		cout<<((h) ? "false" : "true")<<endl;
	}
}