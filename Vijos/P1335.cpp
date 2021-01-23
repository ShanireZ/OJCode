#include <iostream>
#include <cstring>
using namespace std;
int line[10][10];
int row[10][10];
int area[10][10];
bool check()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (line[i][j] > 1 || line[i][j] == 0 || row[i][j] > 1 || row[i][j] == 0 || area[i][j] > 1 || area[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for (int t = 1; t <= n; t++)
	{
		memset(line, 0, sizeof(line));
		memset(row, 0, sizeof(row));
		memset(area, 0, sizeof(area));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int tmp;
				cin >> tmp;
				line[i][tmp]++;
				row[j][tmp]++;
				area[i / 3 * 3 + j / 3][tmp]++;
			}
		}
		if (check())
		{
			cout << "Right" << endl;
		}
		else
		{
			cout << "Wrong" << endl;
		}
	}
	return 0;
}