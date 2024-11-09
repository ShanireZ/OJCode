#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int x, y;
    bool operator<(const Node &oth) const
    {
        if (x == oth.x)
        {
            return y < oth.y;
        }
        return x < oth.x;
    }
};
Node ns[500005];
int q[1000005], n, ed;
int sd(int a, int b, int c) // 左正右负
{
    Node g = Node{ns[b].x - ns[a].x, ns[b].y - ns[a].y};
    Node h = Node{ns[c].x - ns[a].x, ns[c].y - ns[a].y};
    return g.x * h.y - g.y * h.x;
}
int dis2(int a, int b)
{
    return (ns[a].x - ns[b].x) * (ns[a].x - ns[b].x) + (ns[a].y - ns[b].y) * (ns[a].y - ns[b].y);
}
void Andrew()
{
    sort(ns + 1, ns + n + 1);
    ed = 3, q[1] = 1, q[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        while (q[ed - 1] != 1 && sd(q[ed - 2], q[ed - 1], i) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    q[ed++] = n - 1;
    for (int i = n - 2; i >= 1; i--)
    {
        while (q[ed - 1] != n && sd(q[ed - 2], q[ed - 1], i) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
}
void xzkk()
{
    int pos = 2, ans = 0;
    for (int i = 2; i < ed; i++)
    {
        while (sd(q[i - 1], q[i], q[pos]) < sd(q[i - 1], q[i], q[pos + 1]))
        {
            pos == ed - 2 ? pos = 1 : pos = pos + 1;
        }
        ans = max(ans, max(dis2(q[i], q[pos]), dis2(q[i - 1], q[pos])));
    }
    cout << ans << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    Andrew();
    xzkk();
    return 0;
}