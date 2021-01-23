#include <iostream>
#include <climits>
using namespace std;
long long num[200005], d, t;
int pos, m, id, ids[200005];
int main()
{
	cin >> m >> d;
	num[0] = LLONG_MAX;
	for (int i = 1; i <= m; i++) //单调栈
	{
		char op;
		long long n;
		cin >> op >> n;
		if (op == 'Q')
		{
			int tot = 0, cur = pos;
			while (tot < n)
			{
				tot += ids[cur] - ids[cur - 1];
				cur--;
			}
			t = num[cur + 1];
			cout << t << endl;
		}
		else
		{
			n = (n + t) % d;
			id++;
			while (n > num[pos])
			{
				pos--;
			}
			pos++;
			num[pos] = n;
			ids[pos] = id;
		}
	}
	return 0;
}