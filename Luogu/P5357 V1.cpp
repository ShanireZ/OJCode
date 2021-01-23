#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct Node
{
	char v;
	int fa, fail, ch[26], tag, ind;
	vector<int> id;
};
Node ns[200005];
int pos, root;
queue<int> q;
int times[200005];			 //每个子串的出现次数
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
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	root = ++pos;
	for (int i = 1; i <= n; i++) //子串建树
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
				ns[failp].ind++;
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
		ns[p].tag++;
	}
	for (int i = 1; i <= pos; i++)
	{
		if (ns[i].ind == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int from = q.front();
		q.pop();
		int to = ns[from].fail;
		ns[to].ind--;
		if (ns[to].ind == 0 && to != root)
		{
			q.push(to);
		}
		ns[to].tag += ns[from].tag;
		for (int i = 0; i < ns[from].id.size(); i++)
		{
			int id = ns[from].id[i];
			times[id] += ns[from].tag;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << times[i] << endl;
	}
	return 0;
}
//todo 优化1 fail建立时不转移子串编号，处理完毕后按照拓扑序传递出现次数
//todo 优化2 有相同子串，其出现次数应该一致