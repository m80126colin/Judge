#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;
#define MAX 15
#define w 100000

class bigint{
private:
	friend ostream& operator << (ostream& os,const bigint& r);
	int ele[MAX];
public:
	bigint() {
		int i;
		for (i=0;i<MAX;i++) ele[i]=0;
	}
	bigint& operator += (const bigint& r) {
		int i,c=0;
		for (i=0;i<MAX;i++) {
			ele[i]+=r.ele[i]+c;
			c=ele[i]/w;
			ele[i]%=w;
		}
		return *this;
	}
	bigint& operator += (const int& r) {
		int i,c=0;
		ele[0]+=r;
		for (i=0;i<MAX;i++) {
			ele[i]+=c;
			c=ele[i]/w;
			ele[i]%=w;
		}
		return *this;
	}
	bigint operator + (const bigint& r) {
		bigint l=*this;
		return l+=r;
	}
	bigint operator + (const int& r) {
		bigint l=*this;
		return l+=r;
	}
	bigint& operator *= (const bigint& r) {
		int i,j;
		long long c=0;
		bigint l=bigint();
		for (i=0;i<MAX;i++) {
			for (j=0;j<MAX;j++) {
				c=(long long) ele[i]*r.ele[j];
				l.ele[i+j]+=c%w;
				l.ele[i+j+1]+=c/w;
			}
		}
		l+=0;
		return (*this)=l;
	}
	bigint& operator *= (const int& r) {
		int i;
		for (i=0;i<MAX;i++) ele[i]*=r;
		(*this)+=0;
		return *this;
	}
	bigint operator * (const bigint& r) {
		bigint l=*this;
		return l*=r;
	}
	bigint operator * (const int& r) {
		bigint l=*this;
		return l*=r;
	}
	bigint& operator = (int r) {
		(*this)=bigint();
		return (*this)+=r;
	}
	bool operator < (const bigint& r) {
		int i;
		for (i=MAX-1;i>=0;i--) {
			if (ele[i]!=r.ele[i]) return ele[i] < r.ele[i];
		}
		return 0;
	}
};

ostream& operator << (ostream& os,const bigint& r) {
	bool ox=0;
	int i;
	for (i=MAX-1;i>=0;i--) {
		if (ox) printf("%05d",r.ele[i]);
		else if (r.ele[i]) {
			printf("%d",r.ele[i]);
			ox=1;
		}
	}
	if (!ox) putchar('0');
	return os;
}

int main() {
	static bigint n[10001],d;
	long long i,j,k;
	n[0]=0;d=1;
	for (i=j=k=1;i<=10000;i++) {
		if (!k) k=++j,d*=2;
		n[i]=n[i-1]+d;
		k--;
	}
	while (cin >> i) cout << n[i] << endl;
}