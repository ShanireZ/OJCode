#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> to[55];
string mbs[55], res[55], tmp[55];
int sz[55], zx1, zx2, n, m;
void dfs(int now, int from)
{
    sz[now] = 1;
    int ok = 1;
    for (int nxt : to[now])
    {
        if (from == nxt)
        {
            continue;
        }
        dfs(nxt, now);
        sz[now] += sz[nxt];
        if (sz[nxt] > n / 2)
        {
            ok = 0;
        }
    }
    if (ok && n - sz[now] <= n / 2)
    {
        zx1 == 0 ? zx1 = now : zx2 = now;
    }
}
void dfs2(int now, int from)
{
    res[now] = "1";
    for (int nxt : to[now])
    {
        if (from == nxt)
        {
            continue;
        }
        dfs2(nxt, now);
    }
    int pos = 0;
    for (int nxt : to[now])
    {
        if (from == nxt)
        {
            continue;
        }
        tmp[++pos] = res[nxt];
    }
    sort(tmp + 1, tmp + pos + 1);
    for (int i = 1; i <= pos; i++)
    {
        res[now] += tmp[i];
    }
    res[now] += "2";
}
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        memset(to, 0, sizeof(to));
        memset(sz, 0, sizeof(sz));
        zx1 = 0, zx2 = 0;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            int f;
            cin >> f;
            if (f == 0)
            {
                continue;
            }
            to[f].push_back(j), to[j].push_back(f);
        }
        dfs(1, 0);
        memset(res, 0, sizeof(res));
        dfs2(zx1, 0);
        mbs[i] = res[zx1];
        if (zx2)
        {
            memset(res, 0, sizeof(res));
            dfs2(zx2, 0);
            mbs[i] = min(mbs[i], res[zx2]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int g = i;
        for (int j = 1; j < i; j++)
        {
            if (mbs[i] == mbs[j])
            {
                g = j;
                break;
            }
        }
        cout << g << endl;
    }
    return 0;
}