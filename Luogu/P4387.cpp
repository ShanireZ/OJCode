#include <iostream>
#include <stack>
using namespace std;
int pushed[100005];
int poped[100005];
int main()
{
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		stack<int> stk;
		stk.push(555555);
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> pushed[j];
		}
		for (int j = 1; j <= n; j++)
		{
			cin >> poped[j];
		}
		int p = 1;
		for (int j = 1; j <= n; j++)
		{
			int num = poped[j];
			while (stk.top() != num && p <= n)
			{
				stk.push(pushed[p]);
				p++;
			}
			if (stk.top() == num)
			{
				stk.pop();
			}
			else
			{
				cout << "No" << endl;
				break;
			}
		}
		if (stk.size() == 1)
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}