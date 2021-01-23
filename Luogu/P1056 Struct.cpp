#include <iostream>
#include <algorithm>
using namespace std;
struct Classroom
{
	int total, id;
};
Classroom hang[1005];
Classroom lie[1005];
bool cmp(Classroom a, Classroom b)
{
	return a.total > b.total;
}
bool cmp_id(Classroom a, Classroom b)
{
	return a.id < b.id;
}
int main()
{
	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	for (int i = 1; i <= d; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			lie[min(y1, y2)].total++;
		}
		if (y1 == y2)
		{
			hang[min(x1, x2)].total++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		hang[i].id = i;
	}
	for (int i = 1; i <= n; i++)
	{
		lie[i].id = i;
	}
	sort(hang + 1, hang + m + 1, cmp);
	sort(lie + 1, lie + n + 1, cmp);
	sort(hang + 1, hang + 1 + k, cmp_id);
	sort(lie + 1, lie + 1 + l, cmp_id);
	for (int i = 1; i <= k; i++)
	{
		cout << hang[i].id << " ";
	}
	cout << endl;
	for (int i = 1; i <= l; i++)
	{
		cout << lie[i].id << " ";
	}
	return 0;
}