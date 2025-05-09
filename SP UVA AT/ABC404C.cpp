#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, vis[200005];
vector<int> to[200005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    if (m != n || to[1].size() != 2)
    {
        cout << "No" << endl;
        return 0;
    }
    int from = 1, now = to[1][0], cnt = 1;
    vis[now] = 1;
    while (now != 1)
    {
        if (to[now].size() != 2)
        {
            cout << "No" << endl;
            return 0;
        }
        int tmp = now;
        now = to[now][0] + to[now][1] - from;
        from = tmp;
        if (vis[now])
        {
            cout << "No" << endl;
            return 0;
        }
        vis[now] = 1, cnt++;
    }
    cout << (cnt == n ? "Yes" : "No") << endl;
    return 0;
}