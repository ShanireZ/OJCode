#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node
{
	int num, day;
};
bool cmp(Node a, Node b)
{
	return a.num < b.num;
}
Node node[35000];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> node[i].num;
		node[i].day = i;
	}
	int sum = node[1].num;
	sort(node + 1, node + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		int minn = 0x3f3f3f3f;
		for (int j = i - 1; j >= 1; j--)
		{
			if (node[j].day < node[i].day)
			{
				minn = abs(node[i].num - node[j].num);
				break;
			}
		}
		for (int j = i + 1; j <= n; j++)
		{
			if (node[j].day < node[i].day)
			{
				minn = min(abs(node[i].num - node[j].num), minn);
				break;
			}
		}
		if (node[i].day != 1)
		{
			sum += minn;
		}
	}
	cout << sum;
	return 0;
}