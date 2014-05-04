#include <iostream>
#include <string>
using namespace std;

class bigint{ //很破爛的大數寫法
public:
	int num[51],size,sign; //500位數的大數,長度,正負號及0的判別
	bigint() {
		memset(num,0,sizeof(num));
		size=sign=0;
	}
	int cmp(const bigint& r) { //不比符號的比較運算
		int i,c=(size>r.size)-(size<r.size);
		if (c) return c; //先比位數
		for (i=size;i;i--) {
			c=(num[i]>r.num[i])-(num[i]<r.num[i]);
			if (c) return c; //位數相同再比數字
		}
		return 0;
	}
	bigint& cul1(const bigint& r) { //兩正數相加的運算
		int i,c;
		size=max(size,r.size);
		c=0;
		for (i=1;i<=size+1;i++) {
			num[i]+=r.num[i]+c;
			if (num[i]/10) { //進位
				c=1;
				num[i]%=10;
			}
			else c=0;
		}
		if (num[size+1]) size++; //確認位數
		return *this;
	}
	bigint& cul2(const bigint& r) { //只能大減小的運算
		int i,c;
		c=min(size,r.size);
		for (i=1;i<=c;i++) {
			num[i]-=r.num[i];
			if (num[i]<0) num[i+1]--,num[i]+=10; //不足要補10
		}
		while (!num[size]&&size) size--; //退位
		if (!size) size=1,sign=0; //檢查有沒有掛0
		return *this;
	}
	bigint& cul3(const bigint& r) { //兩非負整數相乘的運算
		bigint s;
		int i,j;
		if (!(sign*r.sign)) { //0的判定
			s.size=1;
			return *this=s;
		}
		for (i=1;i<=size;i++) {
			for (j=1;j<=r.size;j++) {
				int c,k=i+j-1;
				s.num[k]+=num[i]*r.num[j];
				for (c=s.num[i+j-1]/10,k++;c;c/=10) s.num[k]+=c%10; //進位
				s.num[i+j-1]%=10;
			}
		}
		s.size=size+r.size-1; //長度確認
		while (s.num[s.size+1]) s.size++;
		s.sign=sign; //符號
		return *this=s;
	}
	bigint& cul4(const bigint& r) { //兩非負數相除(除數不為0)
		bigint s;
		int i,j;
		if (!sign||cmp(r)==-1) { //檢查0
			s.size=1;
			return *this=s;
		}
		s.size=size-r.size+1; //決定最上限位數
		s.sign=sign;
		for (i=size;i>=r.size;i--) {
			for (j=1;j<=9;j++) { //超暴力除法
				int c;
				s.num[i-r.size+1]=j;
				c=cmp(s*r); //看到這個，這個除法就不只O(n^2)
				if (c==-1) {
					s.num[i-r.size+1]--;
					break;
				}
				else if (!c) {
					i=r.size;
					break;
				}
			}
		}
		while (!s.num[s.size]) s.size--; //確認位數
		return *this=s;
	}
	bigint& operator += (bigint r) { // bigint += bigint
		if (!(sign*r.sign)) return ((sign) ? *this:*this=r); //其中一項為0直接傳回
		else if (sign*r.sign>0) return (*this).cul1(r); //同號相加
		else {
			int c=cmp(r);
			sign*=c;
			return ((c>0) ? (*this).cul2(r):*this=r.cul2(*this)); //異號就讓大的減小的
		}
	}
	bigint operator + (bigint r) { // bigint + bigint
		return r+=*this;
	}
	bigint& operator -= (bigint r) { // bigint -= bigint
		r.sign=-r.sign; // r = -r;
		return *this+=r; // l + (-r)
	}
	bigint operator - (bigint r) { // bigint - bigint
		r.sign=-r.sign;
		return r+=(*this);
	}
	bigint& operator *= (bigint r) { // bigint *= bigint
		sign*=r.sign;
		return (*this).cul3(r);
	}
	bigint operator * (bigint r) { // bigint * bigint
		return r*=(*this);
	}
	bigint& operator /= (bigint r) { // bigint /= bigint
		sign*=r.sign;
		return (*this).cul4(r);
	}
	bigint operator / (bigint r) { // bigint / bigint
		bigint c=*this;
		return c/=r;
	}
	bigint& operator %= (bigint r) { // bigint %= bigint
		return *this-=(*this/r)*r;
	}
	bigint operator % (bigint r) { // bigint % bigint
		bigint c=*this;
		return c%=r;
	}
	friend istream& operator >> (istream& is,bigint& r) { //input
		string s;
		r=bigint();
		cin>>s;
		r.sign=((s[0]=='-') ? -1:1);
		for (int i=s.size();i;i--) {
			if (isdigit(s[i-1])) {
				r.size++;
				r.num[r.size]=s[i-1]-'0';
			}
		}
		if (r.size==1&&!r.num[1]) r.sign=0;
		return is;
	}
	friend ostream& operator << (ostream& os,const bigint& r) { //output
		string s="";
		if (r.sign==-1) s+='-';
		for (int i=r.size;i;i--) s+=(char) r.num[i]+'0';
		cout<<s;
		return os;
	}
};

int main() {
	bigint a,b;
	while (cin>>a>>b) cout<<a/b<<endl;
}