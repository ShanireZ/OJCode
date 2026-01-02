#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int t, x, y;
    bool operator<(const Node &oth) const
    {
        return t < oth.t;
    }
};
Node ns[1005];
int a[1005][1005], b[1005][1005], cnt[1005], n, m, q, T, x, y, now = 1;
int ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    cin >> n >> m >> q >> T >> x >> y;
    a[x][y] = 2; // 熔岩
    cin >> x >> y;
    a[x][y] = 1; // 水
    for (int i = 1; i <= q; i++)
    {
        cin >> ns[i].t >> ns[i].x >> ns[i].y;
    }
    sort(ns + 1, ns + q + 1);
    for (int i = 1; i <= q; i++)
    {
        while (now < ns[i].t)
        {
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= m; y++)
                {
                    if (a[x][y])
                    {
                        b[x][y] = a[x][y] % 3;
                    }
                    else
                    {
                        int c1 = 0, c2 = 0;
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + ms[k][0], ny = y + ms[k][1];
                            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
                            {
                                c1 += (a[nx][ny] == 1);
                                c2 += (a[nx][ny] == 2);
                            }
                        }
                        b[x][y] = (c1 != 0) + (c2 != 0) * 2;
                    }
                }
            }
            swap(a, b), now++;
        }
        cnt[a[ns[i].x][ns[i].y]]++;
    }
    cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
    return 0;
}