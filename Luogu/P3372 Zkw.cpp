#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long tag, v, sz; // tag表示当前点为根的子树上未修改的值
};
Node ns[400005];
void edit(int x, int y, long long k)
{
    long long lcnt = 0, rcnt = 0; // 左、右侧部分有多少点产生了变化
    x--, y++;
    while (x != y)
    {
        ns[x].v += k * lcnt, ns[y].v += k * rcnt;
        if (x / 2 != y / 2)
        {
            if (x % 2 == 0) // 如果x是左儿子，那么右儿子部分全部修改
            {
                ns[x + 1].tag += k, lcnt += ns[x + 1].sz;
            }
            if (y % 2 == 1) // 如果y是右儿子，那么左儿子部分全部修改
            {
                ns[y - 1].tag += k, rcnt += ns[y - 1].sz;
            }
        }
        x /= 2, y /= 2;
    }
    while (x)
    {
        ns[x].v += k * (lcnt + rcnt);
        x /= 2;
    }
}
long long query(int x, int y)
{
    long long lcnt = 0, rcnt = 0, ans = 0;
    x--, y++;
    while (x != y)
    {
        ans += ns[x].tag * lcnt + ns[y].tag * rcnt;
        if (x / 2 != y / 2)
        {
            if (x % 2 == 0)
            {
                ans += ns[x + 1].v + ns[x + 1].tag * ns[x + 1].sz;
                lcnt += ns[x + 1].sz;
            }
            if (y % 2 == 1)
            {
                ans += ns[y - 1].v + ns[y - 1].tag * ns[y - 1].sz;
                rcnt += ns[y - 1].sz;
            }
        }
        x /= 2, y /= 2;
    }
    while (x)
    {
        ans += ns[x].tag * (lcnt + rcnt);
        x /= 2;
    }
    return ans;
}
int main()
{
    int n, m, pre = 1;
    cin >> n >> m;
    while (pre < n + 2) // 寻找最底层位置
    {
        pre *= 2;
    }
    for (int i = 1; i <= n; i++) // 初始化最底层
    {
        cin >> ns[i + pre].v;
        ns[i + pre].sz = 1;
    }
    for (int i = pre - 1; i >= 1; i--) // 初始化上方其他层
    {
        ns[i].v = ns[i * 2].v + ns[i * 2 + 1].v;
        ns[i].sz = ns[i * 2].sz + ns[i * 2 + 1].sz;
    }
    for (int i = 1; i <= m; i++)
    {
        long long op, x, y, k;
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            edit(x + pre, y + pre, k);
        }
        else
        {
            cout << query(x + pre, y + pre) << endl;
        }
    }
    return 0;
}