/**
 *  @judge ZeroJudge
 *  @id d669
 *  @source UVa 11677
 */
#include <iostream>
using namespace std;

int main()
{
	int h1, h2, m1, m2;
	while (cin >> h1 >> m1 >> h2 >> m2, (h1 || h2 || m1 || m2))
	{
		m1 += h1 * 60;
		m2 += h2 * 60; /* �������� */
		m2 -= m1; /* �᭱��e�� */
		if (m2 < 0) m2 += 1440; /* �p�G�O�t�� (�N��¶�L0��0��)�A�[ 1440 �� (�@��) */
		cout << m2 << endl;
	}
}