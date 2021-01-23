#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
	int a, b, w;
};
struct cmp
{
	bool operator()(const Node x, const Node y)
	{
		if (x.w == y.w)
		{
			return x.a > y.a;
		}
		else
		{
			return x.w > y.w;
		}
	}
};
priority_queue<Node, vector<Node>, cmp> q;
int skill[200005]; //武技值
int vis[200005];   //是否已出队
vector<Node> op;   //跳舞的组合
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	str.insert(0, "x");
	for (int i = 1; i <= n; i++)
	{
		cin >> skill[i];
		if (abs(str[i - 1] - str[i]) == 'G' - 'B') //和前方舞友是异性
		{
			Node tmp;
			tmp.a = i - 1;
			tmp.b = i;
			tmp.w = abs(skill[i] - skill[i - 1]);
			q.push(tmp);
		}
	}
	int k = 0;
	while (q.size())
	{
		Node tmp = q.top();
		q.pop();
		if (vis[tmp.a] == 0 && vis[tmp.b] == 0)
		{
			op.push_back(tmp);
			vis[tmp.a] = vis[tmp.b] = 1;
			k++;
			//这两个人出队了 找到他们前面和后面的人 看看他们是不是异性组合
			int l = tmp.a - 1, r = tmp.b + 1;
			while (l >= 1 && vis[l] != 0) //不出界且没出队
			{
				l--;
			}
			while (r <= n && vis[r] != 0)
			{
				r++;
			}
			//l和r存在 且是异性
			if (l != 0 && r != n + 1 && abs(str[l] - str[r]) == 'G' - 'B')
			{
				Node tmp;
				tmp.a = l;
				tmp.b = r;
				tmp.w = abs(skill[l] - skill[r]);
				q.push(tmp);
			}
		}
	}
	cout << k << endl;
	for (int i = 0; i < k; i++)
	{
		cout << op[i].a << " " << op[i].b << endl;
	}
	return 0;
}