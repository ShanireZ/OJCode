#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 1000005
int col[MX][25], tm[MX][25], pw[25], n, q;
void edit(int now, int p, int dis, int k, int l, int r)
{
    if (l == r)
    {
        while (now > 0 && dis >= 0)
        {
            for (int i = 0; i <= min(dis, 20); i++) // 取min防止dis很大出现越界
            {
                col[now][i] = k, tm[now][i] = q;
            }
            now /= 2, dis -= 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid)
    {
        edit(now * 2, p, dis, k, l, mid);
    }
    else
    {
        edit(now * 2 + 1, p, dis, k, mid + 1, r);
    }
}
pair<int, int> query(int now, int p, int &dis, int l, int r)
{
    if (l == r)
    {
        dis++;
        return {col[now][0], tm[now][0]};
    }
    int mid = (l + r) / 2;
    pair<int, int> res;
    if (p <= mid)
    {
        res = query(now * 2, p, dis, l, mid);
    }
    else
    {
        res = query(now * 2 + 1, p, dis, mid + 1, r);
    }
    if (tm[now][dis] < res.second)
    {
        res = {col[now][dis], tm[now][dis]};
    }
    dis++;
    return res;
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        pw[i] = pw[i - 1] * 2;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            tm[i][j] = 0x3f3f3f3f;
        }
    }
    while (q--)
    {
        int opt, x, y, z;
        cin >> opt >> x;
        int t = log2(x);
        int l = pw[t], r = pw[t + 1] - 1;
        if (opt == 1)
        {
            cin >> y >> z;
            edit(1, x, y, z, l, r);
        }
        else
        {
            int dis = 0;
            cout << query(1, x, dis, l, r).first << endl;
        }
    }
    return 0;
}