#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, i, j, pos = 0;
	cin >> n >> m;
	char person[n][15];
	int order[m][2];
	memset(person, 0, sizeof(person));
	memset(order, 0, sizeof(order));
	getchar();
	for (i = 0; i < n; i++)
	{
		j = 0;
		while((person[i][j] = getchar()) != '\n')
		{
			j++;
		}
	}
	for (i = 0; i < m; i++)
	{
		cin >> order[i][0] >> order[i][1];
	}
	for (i = 0; i < m; i++)
	{
		if (order[i][0] == 0)
		{
			if (person[pos][0] == '0')
			{
				j = pos - order[i][1];
			}
			else
			{
				j = pos + order[i][1];
			}
		}
		else
		{
			if (person[pos][0] == '0')
			{
				j = pos + order[i][1];
			}
			else
			{
				j = pos - order[i][1];
			}
		}
		if (j >= 0 && j < n)
		{
			pos = j;
		}
		else if (j >= n)
		{
			pos = j - n;
		}
		else
		{
			pos = j + n;
		}
	}
	i = 2;
	while(person[pos][i] != '\n')
	{
		cout << person[pos][i];
		i++;
	}
	return 0;
}