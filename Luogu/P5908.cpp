#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, d, ans, vis[100005];
queue<pair<int, int>> q;
vector<int> to[100005];
int main()
{
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    q.push({1, 0}), vis[1] = 1, ans = -1;
    while (q.size())
    {
        int now = q.front().first, step = q.front().second;
        q.pop(), ans++;
        if (step == d)
        {
            continue;
        }
        for (int x : to[now])
        {
            if (vis[x] == 0)
            {
                vis[x] = 1;
                q.push({x, step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 树的遍历 dfs bfs 