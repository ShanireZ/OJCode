#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
struct Node
{
    int x, y;
};
Node ns[105];
bool cmp(Node a, Node b)
{
    return a.x < b.x;
}
int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, maxs = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    sort(ns + 1, ns + 1 + n, cmp);
    for (int i = 1; i <= n - 1; i++) //i和j在同一列 即x坐标相同
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (ns[i].x == ns[j].x)
            {
                for (int k = 1; k <= n; k++) //寻找和i j其中一个在同一行的点
                {
                    if (k != i && k != j)
                    {
                        int s = ns[i].y - ns[j].y;
                        if (ns[k].y == ns[i].y)
                        {
                            s *= ns[i].x - ns[k].x;
                        }
                        else if (ns[k].y == ns[j].y)
                        {
                            s *= ns[j].x - ns[k].x;
                        }
                        maxs = max(maxs, abs(s));
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    cout << maxs;
    return 0;
}