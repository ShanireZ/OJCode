#include <iostream>
#include <map>
using namespace std;
int cnt[2][5];
map<char, int> times[2];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char a, b;
		cin >> a >> b;
		if (a == b)
		{
			cnt[0][1]++, cnt[1][1]++;
		}
		else if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C'))
		{
			cnt[0][3]++, cnt[1][0]++;
			times[0][a]++;
		}
		else
		{
			cnt[0][0]++, cnt[1][3]++;
			times[1][b]++;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		cout << cnt[i][3] << " " << cnt[i][1] << " " << cnt[i][0] << "\n";
	}
	for (int i = 0; i < 2; i++)
	{
		if (times[i]['B'] >= times[i]['C'] && times[i]['B'] >= times[i]['J'])
		{
			cout << 'B';
		}
		else if (times[i]['C'] >= times[i]['B'] && times[i]['C'] >= times[i]['J'])
		{
			cout << 'C';
		}
		else
		{
			cout << 'J';
		}
		if (i == 0)
		{
			cout << " ";
		}
	}
	return 0;
}