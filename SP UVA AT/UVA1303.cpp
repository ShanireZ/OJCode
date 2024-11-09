#include <algorithm>
#include <cmath>
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
Node ns[1005];
int n, ed, r, q[1005];
double sd(int a, int b, int c)
{
    Node g = Node{ns[b].x - ns[a].x, ns[b].y - ns[a].y};
    Node h = Node{ns[c].x - ns[a].x, ns[c].y - ns[a].y};
    return g.x * h.y - g.y * h.x;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> r;
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].x >> ns[i].y;
        }
        sort(ns + 1, ns + n + 1);
        q[1] = 1, q[2] = 2, ed = 3;
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
        double ans = 2 * 3.141592653 * r;
        for (int i = 2; i < ed; i++)
        {
            ans += sqrt((ns[q[i]].x - ns[q[i - 1]].x) * (ns[q[i]].x - ns[q[i - 1]].x) + (ns[q[i]].y - ns[q[i - 1]].y) * (ns[q[i]].y - ns[q[i - 1]].y));
        }
        cout << int(ans + 0.5) << endl;
        if (T)
        {
            cout << endl;
        }
    }
    return 0;
}