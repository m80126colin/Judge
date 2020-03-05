#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

struct Date
{
	int year, month, day;
};

bool isleap(int y)
{
	if ( (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)) ) return 1;
	else return 0;
}

int month_day(int y, int m)
{
	if (m == 2)
	{
		if (isleap(y)) return 29;
		else return 28;
	}
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	else return 30;
}

int convert(Date d)
{
	int i, sum = 0;
	for (i = 1; i < d.year; i++)
	{
		if (isleap(i)) sum += 366;
		else sum += 365;
	}
	for (i = 1; i < d.month; i++)
	{
		sum += month_day(d.year, i);
	}
	sum += d.day;
	return sum;
}

void diff(Date date[2])
{
	int sum_day[2];
	sum_day[0] = convert(date[0]);
	sum_day[1] = convert(date[1]);
	freopen("a263.out", "a+", stdout);
	if (sum_day[0] > sum_day[1]) cout << sum_day[0] - sum_day[1] << endl;
	else cout << sum_day[1] - sum_day[0] << endl;
}

int main()
{
	freopen("a263.in", "w", stdout);
	freopen("a263.out", "w", stdout);
	Date date[2];
	while (cin >> date[0].year >> date[0].month >> date[0].day)
	{
		cin >> date[1].year >> date[1].month >> date[1].day;
		freopen("a263.in", "a+", stdout);
		printf("%d %d %d\n", date[0].year, date[0].month, date[0].day);
		printf("%d %d %d\n", date[1].year, date[1].month, date[1].day);
		diff(date);
	}
	int i, j;
	srand(time(NULL));
	for (i = 0; i < 5201; i++)
	{
		for (j = 0; j < 2; j++)
		{
			date[j].year = rand() % 3000 + 1;
			date[j].month = rand() % 12 + 1;
			date[j].day = rand() % month_day(date[j].year, date[j].month) + 1;
		}
		freopen("a263.in", "a+", stdout);
		printf("%d %d %d\n", date[0].year, date[0].month, date[0].day);
		printf("%d %d %d\n", date[1].year, date[1].month, date[1].day);
		diff(date);
	}
}