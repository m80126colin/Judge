/**
 *  @judge CPE
 *  @id 10559
 *  @source UVa 10220
 * 
 *  @tag Simple, Big number
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class BigNum
{
public:
#define MAX 400
#define NBIT 8
#define NMOD 100000000LL

	int digit[MAX];

	BigNum()
	{
		memset(digit, 0, sizeof(digit));
	}
	BigNum& operator = (string str)
	{
		int len = str.size(), i, j = 0;
		memset(digit, 0, sizeof(digit));
		for (i = len; i - 8 > 0; i -= 8)
		{
			digit[j] = atoi( str.substr(i - 8, 8).c_str() );
			j++;
		}
		if (i) digit[j] = atoi( str.substr(0, i).c_str() );
		return (*this);
	}
	BigNum operator * (int num)
	{
		int i;
		BigNum result;
		long long buffer = 0;
		for (i = 0; i < MAX; i++)
		{
			buffer += (long long) num * digit[i];
			result.digit[i] = buffer % NMOD;
			buffer /= NMOD;
		}
		return result;
	}
	BigNum operator *= (int num)
	{
		(*this) = (*this) * num;
		return (*this);
	}
	int CountSum()
	{
		int i, sum, tmp;
		for (sum = i = 0; i < MAX; i++)
		{
			tmp = digit[i];
			while (tmp)
			{
				sum += tmp % 10;
				tmp /= 10;
			}
		}
		return sum;
	}
};

int Result[1010];

int main()
{
	int i, n;
	BigNum A;
	A = "1";
	Result[0] = 1;
	for (i = 1; i <= 1000; i++)
	{
		A *= i;
		Result[i] = A.CountSum();
	}
	while (scanf("%d", &n) != EOF)
		printf("%d\n", Result[n]);
}