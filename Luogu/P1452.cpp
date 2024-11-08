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
int sd(Node a, Node b, Node c) // 左正右负
{
    Node g = Node{b.x - a.x, b.y - a.y};
    Node h = Node{c.x - a.x, c.y - a.y};
    return g.x * h.y - g.y * h.x;
}
int dis2(Node a, Node b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void Andrew()
{
    sort(ns + 1, ns + n + 1);
    ed = 3, q[1] = 1, q[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        while (q[ed - 1] != 1 && sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    q[ed++] = n - 1;
    for (int i = n - 2; i >= 1; i--)
    {
        while (q[ed - 1] != n && sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]) <= 0)
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
        while (sd(ns[q[i - 1]], ns[q[i]], ns[q[pos]]) < sd(ns[q[i - 1]], ns[q[i]], ns[q[pos + 1]]))
        {
            pos == ed - 2 ? pos = 1 : pos = pos + 1;
        }
        ans = max(ans, max(dis2(ns[q[i]], ns[q[pos]]), dis2(ns[q[i - 1]], ns[q[pos]])));
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