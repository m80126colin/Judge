// By ms0472904
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 630

int M[MAX][MAX];     //Matrix
int N;               //矩陣邊長
int n, m;

inline void getd(int &d, char ch=0)  //輸入優化
{
	while(!isdigit(ch=getchar()));
	for(d=0; isdigit(ch); ch=getchar())
		d = d * 10 + (ch ^ 48);
}

inline int getID(int x, int y)
{
	return x * m + y;
}

inline bool OnBoard(int x, int y)  //判斷是否在盤面上
{
	return x>=0 && y>=0 && x<n && y<m;
}

inline void MyXor(int a, int b)  //Xor
{
	for(int i=0; i<N; i++)
		M[b][i] ^= M[a][i];
}

inline int Solve()  //高斯消去法 (gaussian-elimination)
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=i; j<N; j++)
		{
			if(M[j][i] == 1)
				break;
		}
		if(j >= N)
			continue;
		if(i != j)
			MyXor(j, i);
		for(j=0; j<=N; j++)
		{
			if(i == j)
				continue;
			if(M[j][i] == 1)
				MyXor(i, j);
		}
	}
	for(i=0; i<N; i++)
		if(M[N][i] == 1)
			return 0;
	return 1;
}

int main()
{
	int d;
	while(getd(m), getd(n), getd(d), n || m || d)
	{
		memset(M, 0, sizeof(M));
		N = n * m;
		for(int i=0; i<n; i++)       //建出矩陣
		{
			for(int j=0; j<m; j++)
			{
				int id = getID(i, j);
				M[id][id] = 1;
				for(int dx = -d; dx <= d; dx ++)
				{
					int dy = d - abs(dx);   //dx + dy = d

					int x = i + dx;
					int y = j + dy;
					
					if(OnBoard(x, y))
						M[id][getID(x, y)] = 1;
					
					dy = -dy;

					x = i + dx;
					y = j + dy;
					
					if(OnBoard(x, y))
						M[id][getID(x, y)] = 1;
				}
			}
		}
		for(int i=0; i<N; i++)
			getd(M[N][i]);
		printf("%d\n", Solve());
	}
}