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
double sd(Node a, Node b, Node c) // 左正右负
{
    Node g = Node{b.x - a.x, b.y - a.y}, h = Node{c.x - a.x, c.y - a.y};
    return g.x * h.y - g.y * h.x;
}
int main()
{
    double a, b, r;
    cin >> n >> a >> b >> r;
    a = a / 2 - r, b = b / 2 - r;
    for (int i = 1; i <= n; i++) // 四个角的圆心
    {
        double x, y, theta;
        cin >> x >> y >> theta;
        ns[++pos] = Node{b * cos(theta) - a * sin(theta) + x, a * cos(theta) + b * sin(theta) + y};
        ns[++pos] = Node{-b * cos(theta) - a * sin(theta) + x, a * cos(theta) - b * sin(theta) + y};
        ns[++pos] = Node{b * cos(theta) + a * sin(theta) + x, -a * cos(theta) + b * sin(theta) + y};
        ns[++pos] = Node{-b * cos(theta) + a * sin(theta) + x, -a * cos(theta) - b * sin(theta) + y};
    }
    sort(ns + 1, ns + 1 + pos);
    double ans = 2 * 3.141592653 * r; // 凸包 + 4个1/4圆
    q[1] = 1, q[2] = 2, ed = 3;
    for (int i = 3; i <= pos; i++)
    {
        while (ed >= 3 && sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    for (int i = 2; i < ed; i++)
    {
        ans += sqrt((ns[q[i]].x - ns[q[i - 1]].x) * (ns[q[i]].x - ns[q[i - 1]].x) + (ns[q[i]].y - ns[q[i - 1]].y) * (ns[q[i]].y - ns[q[i - 1]].y));
    }
    q[1] = pos, q[2] = pos - 1, ed = 3;
    for (int i = pos - 2; i >= 1; i--)
    {
        while (ed >= 3 && sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]) <= 0)
        {
            ed--;
        }
        q[ed++] = i;
    }
    for (int i = 2; i < ed; i++)
    {
        ans += sqrt((ns[q[i]].x - ns[q[i - 1]].x) * (ns[q[i]].x - ns[q[i - 1]].x) + (ns[q[i]].y - ns[q[i - 1]].y) * (ns[q[i]].y - ns[q[i - 1]].y));
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}