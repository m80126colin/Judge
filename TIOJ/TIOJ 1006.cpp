#include <iostream>
#include <string>
using namespace std;

class bigint{ //�ܯ}�ꪺ�j�Ƽg�k
public:
	int num[51],size,sign; //500��ƪ��j��,����,���t����0���P�O
	bigint() {
		memset(num,0,sizeof(num));
		size=sign=0;
	}
	int cmp(const bigint& r) { //����Ÿ�������B��
		int i,c=(size>r.size)-(size<r.size);
		if (c) return c; //������
		for (i=size;i;i--) {
			c=(num[i]>r.num[i])-(num[i]<r.num[i]);
			if (c) return c; //��ƬۦP�A��Ʀr
		}
		return 0;
	}
	bigint& cul1(const bigint& r) { //�⥿�Ƭۥ[���B��
		int i,c;
		size=max(size,r.size);
		c=0;
		for (i=1;i<=size+1;i++) {
			num[i]+=r.num[i]+c;
			if (num[i]/10) { //�i��
				c=1;
				num[i]%=10;
			}
			else c=0;
		}
		if (num[size+1]) size++; //�T�{���
		return *this;
	}
	bigint& cul2(const bigint& r) { //�u��j��p���B��
		int i,c;
		c=min(size,r.size);
		for (i=1;i<=c;i++) {
			num[i]-=r.num[i];
			if (num[i]<0) num[i+1]--,num[i]+=10; //�����n��10
		}
		while (!num[size]&&size) size--; //�h��
		if (!size) size=1,sign=0; //�ˬd���S����0
		return *this;
	}
	bigint& cul3(const bigint& r) { //��D�t��Ƭۭ����B��
		bigint s;
		int i,j;
		if (!(sign*r.sign)) { //0���P�w
			s.size=1;
			return *this=s;
		}
		for (i=1;i<=size;i++) {
			for (j=1;j<=r.size;j++) {
				int c,k=i+j-1;
				s.num[k]+=num[i]*r.num[j];
				for (c=s.num[i+j-1]/10,k++;c;c/=10) s.num[k]+=c%10; //�i��
				s.num[i+j-1]%=10;
			}
		}
		s.size=size+r.size-1; //���׽T�{
		while (s.num[s.size+1]) s.size++;
		s.sign=sign; //�Ÿ�
		return *this=s;
	}
	bigint& cul4(const bigint& r) { //��D�t�Ƭ۰�(���Ƥ���0)
		bigint s;
		int i,j;
		if (!sign||cmp(r)==-1) { //�ˬd0
			s.size=1;
			return *this=s;
		}
		s.size=size-r.size+1; //�M�w�̤W�����
		s.sign=sign;
		for (i=size;i>=r.size;i--) {
			for (j=1;j<=9;j++) { //�W�ɤO���k
				int c;
				s.num[i-r.size+1]=j;
				c=cmp(s*r); //�ݨ�o�ӡA�o�Ӱ��k�N���uO(n^2)
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
		while (!s.num[s.size]) s.size--; //�T�{���
		return *this=s;
	}
	bigint& operator += (bigint r) { // bigint += bigint
		if (!(sign*r.sign)) return ((sign) ? *this:*this=r); //�䤤�@����0�����Ǧ^
		else if (sign*r.sign>0) return (*this).cul1(r); //�P���ۥ[
		else {
			int c=cmp(r);
			sign*=c;
			return ((c>0) ? (*this).cul2(r):*this=r.cul2(*this)); //�����N���j����p��
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