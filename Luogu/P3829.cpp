#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
struct Node
{
    double x, y;
    bool operator<(const Node &oth) const
    {
        return x == oth.x ? y < oth.y : x < oth.x;
    }
};
Node ns[40005];
int n, pos, ed, q[40005];
double sd(int a, int b, int c) // 左正右负
{
    Node g = Node{ns[b].x - ns[a].x, ns[b].y - ns[a].y};
    Node h = Node{ns[c].x - ns[a].x, ns[c].y - ns[a].y};
    return g.x * h.y - g.y * h.x;
}
int main()
{
    double a, b, r;
    cin >> n >> a >> b >> r;
    a = a / 2 - r, b = b / 2 - r;
    for (int i = 1; i <= n; i++) // 四个角的圆心
    {
        double x, y, sta;
        cin >> x >> y >> sta;
        ns[++pos] = Node{b * cos(sta) - a * sin(sta) + x, a * cos(sta) + b * sin(sta) + y};
        ns[++pos] = Node{-b * cos(sta) - a * sin(sta) + x, a * cos(sta) - b * sin(sta) + y};
        ns[++pos] = Node{b * cos(sta) + a * sin(sta) + x, -a * cos(sta) + b * sin(sta) + y};
        ns[++pos] = Node{-b * cos(sta) + a * sin(sta) + x, -a * cos(sta) - b * sin(sta) + y};
    }
    sort(ns + 1, ns + 1 + pos);
    q[1] = 1, q[2] = 2, ed = 3;
    for (int i = 3; i <= pos; i++)
    {
        while (q[ed - 1] != 1 && sd(q[ed - 2], q[ed - 1], i) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    q[ed++] = pos - 1;
    for (int i = pos - 2; i >= 1; i--)
    {
        while (q[ed - 1] != pos && sd(q[ed - 2], q[ed - 1], i) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    double ans = 2 * 3.141592653 * r; // 凸包 + 4个1/4圆
    for (int i = 2; i < ed; i++)
    {
        ans += sqrt((ns[q[i]].x - ns[q[i - 1]].x) * (ns[q[i]].x - ns[q[i - 1]].x) + (ns[q[i]].y - ns[q[i - 1]].y) * (ns[q[i]].y - ns[q[i - 1]].y));
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}