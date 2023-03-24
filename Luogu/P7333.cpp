#include <cstring>
#include <iostream>
#include <set>
using namespace std;
#define MX 100005
struct Node
{
    int id, val;
    bool operator<(const Node oth) const
    {
        return (val == oth.val) ? (id > oth.id) : (val < oth.val);
    }
};
multiset<Node> s;
int a[MX], b[MX], dis[MX], read();
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = read();
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n * 2; i++)
    {
        int now = (i > n ? i - n : i);
        while (s.size() && s.begin()->val <= a[now] && s.begin()->id != now)
        {
            dis[s.begin()->id] = i - s.begin()->id, s.erase(s.begin());
        }
        if (i <= n)
        {
            s.insert(Node{i, b[i]});
        }
    }
    s.clear();
    for (int i = n; i >= 1 - n; i--)
    {
        int now = (i < 1 ? i + n : i);
        while (s.size() && s.begin()->val <= a[now] && s.begin()->id != now)
        {
            dis[s.begin()->id] = min(dis[s.begin()->id], s.begin()->id - i), s.erase(s.begin());
        }
        if (i >= 1)
        {
            s.insert(Node{i, b[i]});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", (dis[i] == 0x3f3f3f3f) ? -1 : dis[i]);
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
// TAG: 单调栈 元素最近距离