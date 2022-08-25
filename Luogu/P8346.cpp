#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 2000005
int t, n, m, dg[MX], vis[MX];
vector<int> to[MX];
queue<int> q;
int main()
{
    cin >> t;
    while (t--)
    {
        memset(dg, 0, sizeof(dg));
        memset(vis, 0, sizeof(vis));
        memset(to, 0, sizeof(to));
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            b += n;
            to[a].push_back(b), to[b].push_back(a);
            dg[a]++, dg[b]++;
        }
        int ans = n * 2;
        for (int i = 1; i <= n; i++)
        {
            if (dg[i] == 1)
            {
                q.push(i);
            }
        }
        while (q.size())
        {
            int now = q.front();
            q.pop(), ans--, vis[now] = 1;
            int tar = 0;
            for (int i = 0; i < int(to[now].size()); i++)
            {
                int t = to[now][i];
                if (vis[t] == 0)
                {
                    tar = t, vis[t] = 1, ans--;
                    break;
                }
            }
            for (int i = 0; i < int(to[tar].size()); i++)
            {
                int t = to[tar][i];
                if (vis[t] == 0 && --dg[t] == 1)
                {
                    q.push(t);
                }
            }
        }
        if (ans == 0)
        {
            cout << "Renko" << endl;
        }
        else
        {
            cout << "Merry" << endl;
        }
    }
    return 0;
}