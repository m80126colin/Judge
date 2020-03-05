#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Bignum
{
private:
	static const int BIGNUM_MAX = 1000;
	static const int BIGNUM_LEN = BIGNUM_MAX / 8 + 1;
	static const int BIGNUM_MOD = 100000000;
	int arr[BIGNUM_LEN];
public:
	int getArr(int index)
	{
		return arr[index];
	}
	Bignum()
	{
		memset(arr, 0, sizeof(arr));
	}
	Bignum(int num)
	{
		memset(arr, 0, sizeof(arr));
		arr[0] = num;
		if (arr[0] / BIGNUM_MOD)
		{
			arr[1] = arr[0] / BIGNUM_MOD;
			arr[0] %= BIGNUM_MOD;
		}
	}
	Bignum& operator += (Bignum Bnum)
	{
		int i;
		for (i = 0; i < BIGNUM_LEN; i++)
		{
			arr[i] += Bnum.getArr(i);
			if (arr[i] / BIGNUM_MOD)
			{
				if (i + 1 < BIGNUM_LEN) arr[i + 1] += arr[i] / BIGNUM_MOD;
				arr[i] %= BIGNUM_MOD;
			}
		}
		return (*this);
	}
	Bignum operator + (const Bignum& Bnum)
	{
		Bignum Cnum = (*this);
		Cnum += Bnum;
		return Cnum;
	}
	friend ostream& operator << (ostream& os, Bignum Bnum)
	{
		int i, flag = 0;
		for (i = BIGNUM_LEN - 1; i >= 0; i--)
		{
			if (flag) printf("%08d", Bnum.getArr(i));
			else if (Bnum.getArr(i))
			{
				printf("%d", Bnum.getArr(i));
				flag = 1;
			}
			else if (i == 0)
				printf("0");
		}
		return os;
	}
};

Bignum DP[251];

int main()
{
	int i;
	DP[0] = DP[1] = 1;
	for (i = 2; i <= 250; i++)
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 2];
	while (scanf("%d", &i) != EOF)
		cout << DP[i] << endl;
}