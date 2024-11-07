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
        if (x == oth.x)
        {
            return y < oth.y;
        }
        return x < oth.x;
    }
};
Node ns[100005];
int q[100005], n, ed;
double sd(Node a, Node b, Node c)
{
    Node g = Node{b.x - a.x, b.y - a.y};
    Node h = Node{c.x - a.x, c.y - a.y};
    return g.x * h.y - g.y * h.x;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    sort(ns + 1, ns + n + 1);
    q[1] = 1, q[2] = 2, ed = 3;
    for (int i = 3; i <= n; i++)
    {
        while (ed >= 3)
        {
            double now = sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]);
            if (now <= 0) // 左正右负
            {
                ed--;
            }
            else
            {
                break;
            }
        }
        q[ed++] = i;
    }
    double ans = 0;
    for (int i = 2; i < ed; i++)
    {
        ans += sqrt((ns[q[i]].x - ns[q[i - 1]].x) * (ns[q[i]].x - ns[q[i - 1]].x) + (ns[q[i]].y - ns[q[i - 1]].y) * (ns[q[i]].y - ns[q[i - 1]].y));
    }
    q[1] = n, q[2] = n - 1, ed = 3;
    for (int i = n - 2; i >= 1; i--)
    {
        while (ed >= 3)
        {
            double now = sd(ns[q[ed - 2]], ns[q[ed - 1]], ns[i]);
            if (now <= 0) // 左正右负
            {
                ed--;
            }
            else
            {
                break;
            }
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