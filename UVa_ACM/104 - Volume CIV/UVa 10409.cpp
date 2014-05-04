#include <iostream>
#include <string>
using namespace std;

int main() {
	string b;
	int a,n,s,w,e,up,down,t;
	while (cin>>a&&a) {
		up=1;
		n=2;
		w=3;
		e=4;
		s=5;
		down=6;
		while (a--) {
			cin>>b;
			if (b=="north") {
				t=up;
				up=s;
				s=down;
				down=n;
				n=t;
			}
			if (b=="south") {
				t=up;
				up=n;
				n=down;
				down=s;
				s=t;
			}
			if (b=="east") {
				t=up;
				up=w;
				w=down;
				down=e;
				e=t;
			}
			if (b=="west") {
				t=up;
				up=e;
				e=down;
				down=w;
				w=t;
			}
		}
		cout<<up<<endl;
	}
}