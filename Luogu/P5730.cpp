#include <iostream>
#include <string>
using namespace std;
int main()
{
	string all[5];
	all[0] = "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX.";
	all[1] = "X.X...X...X...X.X.X.X...X.....X.X.X.X.X.";
	all[2] = "X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX.";
	all[3] = "X.X...X.X.....X...X...X.X.X...X.X.X...X.";
	all[4] = "XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX.";
	string num[10][5];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			num[i][j] = all[j].substr(i * 4, 4);
		}
	}
	int n;
	string s, ans[5];
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int id = s[i] - '0';
		for (int j = 0; j < 5; j++)
		{
			ans[j].append(num[id][j]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		int last = ans[i].size() - 1;
		ans[i].erase(last);
		cout << ans[i] << endl;
	}
	return 0;
}