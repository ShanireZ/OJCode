#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt, p[2005], vis[2005], anc[2005][2005];
long long tot, v[2005], zs[2005];
vector<int> chs[2005];
void makeanc(int now)
{
    anc[now][now] = 1;
    for (int ch : chs[now])
    {
        int x = now;
        while (x)
        {
            anc[ch][x] = 1, x = p[x];
        }
        makeanc(ch);
    }
}
void makezs(int now)
{
    if (vis[now])
    {
        zs[now] = v[now], tot += v[now];
    }
    for (int ch : chs[now])
    {
        makezs(ch);
        if (vis[now] && vis[ch])
        {
            zs[now] += zs[ch];
        }
    }
}
void delzs(int now)
{
    vis[now] = 0, cnt--;
    for (int ch : chs[now])
    {
        if (vis[ch])
        {
            delzs(ch);
        }
    }
}
void delanc(int now, int ex)
{
    vis[now] = 0, cnt--;
    for (int ch : chs[now])
    {
        if (vis[ch] && ch != ex)
        {
            delanc(ch, ex);
        }
    }
    if (vis[p[now]])
    {
        delanc(p[now], ex);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        chs[p[i]].emplace_back(i);
    }
    makeanc(1);
    while (m--)
    {
        int t;
        cin >> t;
        fill(vis + 1, vis + n + 1, 1), cnt = n;
        while (cnt > 1)
        {
            tot = 0, makezs(1);
            long long minv = 1e18, minp = 0;
            for (int i = 1; i <= n; i++)
            {
                long long w = abs(zs[i] * 2 - tot);
                if (vis[i] && w < minv)
                {
                    minv = w, minp = i;
                }
            }
            cout << minp << " ";
            if (anc[t][minp] == 0)
            {
                delzs(minp);
            }
            else if (vis[p[minp]])
            {
                delanc(p[minp], minp);
            }
        }
        cout << endl;
    }
    return 0;
}