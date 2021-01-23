#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct Node
{
	char v;
	int fa, fail, ch[26];
	vector<int> id;
};
Node ns[1000005];
int pos, root;
queue<int> q;
set<int> s;
int newnode(int now, char x) //新点定位 返回新点id
{
	if (ns[now].ch[x - 'a'] == 0)
	{
		ns[++pos].v = x;
		ns[pos].fa = now;
		ns[now].ch[x - 'a'] = pos;
	}
	return ns[now].ch[x - 'a'];
}
int findp(int now, char x) //从now开始 寻找字符x的位置
{
	while (ns[now].ch[x - 'a'] == 0) //如果找到目标字符则停止
	{
		now = ns[now].fail;
		if (now == 0) //root的fail为0 说明探索完毕没找到目标字符
		{
			break;
		}
	}
	now = ns[now].ch[x - 'a']; //目标字符位置
	if (now == 0)
	{
		now = root; //没找到定位到root
	}
	return now;
}
int main()
{
	int n;
	cin >> n;
	root = ++pos;
	for (int i = 1; i <= n; i++) //建树
	{
		string str;
		cin >> str;
		int now = root;
		for (int j = 0; j < str.size(); j++)
		{
			now = newnode(now, str[j]);
		}
		ns[now].id.push_back(i); //在终止位置记录该子串编号
	}
	for (int i = 0; i < 26; i++) //第一层入队并初始化第一层的fail
	{
		int id = ns[root].ch[i];
		if (id != 0)
		{
			q.push(id);
			ns[id].fail = root;
		}
	}
	while (q.size())
	{
		int from = q.front();
		for (int i = 0; i < 26; i++)
		{
			int to = ns[from].ch[i];
			if (to != 0)
			{
				q.push(to);
				int failp = findp(ns[from].fail, ns[to].v);
				ns[to].fail = failp;
				if (ns[failp].id.size()) //转移所含子串
				{
					for (int j = 0; j < ns[failp].id.size(); j++)
					{
						ns[to].id.push_back(ns[failp].id[j]);
					}
				}
			}
		}
		q.pop();
	}
	string str;
	cin >> str;
	int p = root;
	for (int i = 0; i < str.size(); i++)
	{
		p = findp(p, str[i]);
		if (ns[p].id.size()) //将出现的子串编号加入set中
		{
			for (int j = 0; j < ns[p].id.size(); j++)
			{
				s.insert(ns[p].id[j]);
			}
		}
	}
	cout << s.size();
	return 0;
}