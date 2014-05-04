#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
using namespace std;

const int Maxn = 1000;
const int Maxd = 4;
const int Mod = 10000;
class bigint
{
public:
	int sign, len;
	int s[Maxn];
	bigint()
	{
		memset(s, 0, sizeof(s));
		sign = 0;
		len = 1;
	}
	int strnum(const char *num, int len)
	{
		int i, ans = 0;
		for (i = 0; i < len; i++) ans = 10 * ans + num[i] - '0';
		return ans;
	}
	bigint operator = (const char *num)
	{
		int i = strlen(num);
		sign = 0;
		if (num[0] == '-') sign = 1;
		memset(s, 0, sizeof(s));
		for (len = 0; len < Maxn && i - Maxd > sign; len++, i -= Maxd) s[len] = strnum(num + i - Maxd, Maxd);
		s[len++] = strnum(num + sign, i - sign);
		while (len > 1 && s[len - 1] == 0) len--;
		if (len == 1 && s[len - 1] == 0) sign = 0;
		return *this;
	}
	bigint operator = (int num)
	{
		char s[Maxd * Maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	bigint(const char *num) { *this = num; }
	bigint(int num) { *this = num; }
	string str() const
	{
		string res = "";
		for (int i = 0; i < len; i++)
		{
			int tmp = s[i];
			for (int j = 0; j < Maxd; j++)
			{
				if (i + 1 == len && tmp == 0) break;
				res = (char) (tmp % 10 + '0') + res;
				tmp /= 10;
			}
		}
		if (res == "") res = "0";
		if (sign) res = "-" + res;
		return res;
	}
	friend istream& operator >> (istream& in, bigint& x)
	{
		string s;
		in >> s;
		x = s.c_str();
		return in;
	}
	friend ostream& operator << (ostream& out, const bigint& x)
	{
		out << x.str();
		return out;
	}
	bigint operator << (const int& num) const
	{
		bigint a = *this;
		a.len += num;
		if (a.len > Maxn) a.len = Maxn;
		for (int i = a.len - num - 1; i >= 0; i--) a.s[i + num] = a.s[i];
		for (int i = num - 1; i >= 0; i--) a.s[i] = 0;
		while (a.len > 1 && a.s[a.len - 1] == 0) a.len--;
		if (a.len == 1 && a.s[0] == 0) a.sign = 0;
		return a;
	}
	bigint& operator <<= (const int& num)
	{
		*this = (*this) << num;
		return *this;
	}
	bigint operator >> (const int& num) const
	{
		bigint a = *this;
		a.len -= num;
		if (a.len < 0) a.len = 0;
		for (int i = 0; i < len - num; i++) a.s[i] = a.s[i + num];
		for (int i = len - num; i < len; i++) a.s[i] = 0;
		if (a.len == 1 && a.s[0] == 0) a.sign = 0;
		return a;
	}
	bigint& operator >>= (const int& num)
	{
		*this = (*this) >> num;
		return *this;
	}
	friend bigint abs(bigint num)
	{
		if (num.sign) num.sign = 0;
		return num;
	}
	friend bigint pow(bigint num, int power)
	{
		bigint a = num, ans = 1;
		for (; power; power >>= 1)
		{
			if (power & 1) ans *= a;
			a *= a;
		}
		return ans;
	}
	bigint operator -() const
	{
		bigint a = *this;
		if (sign) a.sign = 0;
		else a.sign = 1;
		if (a.len == 1 && a.s[0] == 0) a.sign = 0;
		return a;
	}
	bigint operator + (const bigint& num) const
	{
		if (sign != num.sign) return (*this) - (-num);
		bigint a;
		a.sign = sign;
		a.len = 0;
		for (int i = 0, g = 0; (g || i < max(len, num.len)) && i < Maxn; i++)
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < num.len) x += num.s[i];
			a.s[a.len++] = x % Mod;
			g = x / Mod;
		}
		return a;
	}
	bigint& operator += (const bigint& num)
	{
		*this = *this + num;
		return *this;
	}
	bigint operator - (const bigint& num) const
	{
		if (sign != num.sign) return *this + (-num);
		if (abs(*this) < abs(num)) return -(num - *this);
		bigint a;
		a.sign = sign;
		a.len = 0;
		for (int i = 0, g = 0; (g || i < len) && i < Maxn; i++)
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < num.len) x -= num.s[i];
			if (x >= 0) a.s[a.len++] = x % Mod;
			else
			{
				a.s[a.len++] = (x % Mod + Mod) % Mod;
				x -= Mod;
			}
			g = x / Mod;
		}
		while (a.len > 1 && a.s[a.len - 1] == 0) a.len--;
		if (a.len == 1 && a.s[0] == 0) a.sign = 0;
		return a;
	}
	bigint& operator -= (const bigint& num)
	{
		*this = *this - num;
		return *this;
	}
	bigint operator * (const bigint& num) const
	{
		bigint a;
		a.sign = sign ^ num.sign;
		a.len = min(Maxn, num.len + len);
		for (int i = 0; i < num.len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (i + j < Maxn)
				{
					a.s[i + j] += num.s[i] * s[j];
					if (a.s[i + j] >= Mod)
					{
						if (i + j + 1 < Maxn) a.s[i + j + 1] += a.s[i + j] / Mod;
						a.s[i + j] %= Mod;
					}
				}
			}
		}
		while (a.len > 1 && a.s[a.len - 1] == 0) a.len--;
		if (a.len == 1 && a.s[0] == 0) a.sign = 0;
		return a;
	}
	bigint& operator *= (const bigint& num)
	{
		*this = *this * num;
		return *this;
	}
	bigint operator / (const bigint& num) const
	{
		bigint res, a = *this, b = num;
		// if (b.len == 1 && b.s[0] == 0) { exit(1); }
		res.sign = a.sign ^ b.sign;
		for (res.len = 1; res.len + 1 < Maxn && b < (b << 1) && (b << 1) < *this; res.len++) b <<= 1;
		for (int i = res.len - 1; i >= 0; i--)
		{
			int x = (a.s[b.len] * Mod + a.s[b.len - 1]) / b.s[b.len - 1];
			res.s[i] += x;
			a -= (b * bigint(x));
			b >>= 1;
		}
		while (res.len > 1 && res.s[res.len - 1] == 0) res.len--;
		if (res.len == 1 && res.s[0] == 0) res.sign = 0;
		return res;
	}
	bigint& operator /= (const bigint& num)
	{
		*this = *this / num;
		return *this;
	}
	bigint operator % (const bigint& num) const
	{
		bigint res = *this / num;
		return *this - res * num;
	}
	bigint& operator %= (const bigint& num)
	{
		*this = *this % num;
		return *this;
	}
	bool operator < (const bigint& num) const
	{
		if (len != num.len) return len < num.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != num.s[i]) return s[i] < num.s[i];
		return false;
	}
	bool operator > (const bigint& num) const { return num < *this; }
	bool operator <= (const bigint& num) const { return !(num < *this); }
	bool operator >= (const bigint& num) const { return !(*this < num); }
	bool operator != (const bigint& num) const { return num < *this || *this < num; }
	bool operator == (const bigint& num) const { return !(num < *this) && !(*this < num); }
};

int main()
{
	bigint ans = 0;
	int i;
	for (i = 1; i <= 1000; i++)
		ans += pow(bigint(i), i);
	cout << ans << endl;
}