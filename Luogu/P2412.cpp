#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
struct Node
{
	string x, y; //x原单词 y小写版本
	int id;		 //编号
};
Node ns[50005];
int cnt[50005][20];
bool checks(string a, string b)
{
	for (int i = 0; i < min(a.size(), b.size()); i++)
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		else if (a[i] < b[i])
		{
			return 0;
		}
	}
	if (a.size() > b.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].x;
		ns[i].id = i;
		ns[i].y = ns[i].x;
		transform(ns[i].y.begin(), ns[i].y.end(), ns[i].y.begin(), towlower);
		cnt[i][0] = i;
	}
	for (int k = 1; k <= log2(n); k++)
	{
		for (int i = 1; i + pow(2, k) - 1 <= n; i++)
		{
			int mid = i + pow(2, k - 1);
			Node a = ns[cnt[i][k - 1]];
			Node b = ns[cnt[mid][k - 1]];
			if ((a.y == b.y && a.id > b.id) || checks(a.y, b.y))
			{
				cnt[i][k] = cnt[i][k - 1];
			}
			else
			{
				cnt[i][k] = cnt[mid][k - 1];
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		int t = log2(b - a + 1);
		int mid = b - pow(2, t) + 1;
		Node aa = ns[cnt[a][t]];
		Node bb = ns[cnt[mid][t]];
		if ((aa.y == bb.y && aa.id > bb.id) || checks(aa.y, bb.y))
		{
			cout << aa.x << endl;
		}
		else
		{
			cout << bb.x << endl;
		}
	}
	return 0;
}