#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> to[1000005];
int vis[1000005];
queue<int> q;
int main()
{
    int m, n, k, cnt = 0;
    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    for (int i = 1; i <= n * m; i++)
    {
        if (vis[i] == 0)
        {
            q.push(i), vis[i] = 1, cnt++;
            while (q.size())
            {
                int now = q.front();
                q.pop();
                for (auto nxt : to[now])
                {
                    if (vis[nxt] == 0)
                    {
                        q.push(nxt), vis[nxt] = 1;
                    }
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}