#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> to[200005], rec[200005];
int n, m, k, st, cnt, pos, vis[200005], bz[200005];
void bfs()
{
    q.push(st), vis[st] = cnt = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (bz[now])
        {
            continue;
        }
        vector<int> tmp;
        for (int nxt : to[now])
        {
            if (vis[nxt] == 0)
            {
                q.push(nxt), vis[nxt] = 1, cnt++;
                tmp.push_back(nxt);
            }
        }
        if (tmp.size())
        {
            rec[++pos].push_back(now);
            for (int v : tmp)
            {
                rec[pos].push_back(v);
            }
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        bz[x] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (bz[i] == 0)
        {
            st = i;
            break;
        }
    }
    bfs();
    if (cnt != n)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl
         << pos << endl;
    for (int i = 1; i <= pos; i++)
    {
        cout << rec[i][0] << " " << rec[i].size() - 1 << " ";
        for (int j = 1; j < (int)rec[i].size(); j++)
        {
            cout << rec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}