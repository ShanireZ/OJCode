#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> g[505];
set<int> s[505][25]; // s[i][j]表示点i第j步能到哪些点
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        s[i][0].insert(i);
    }
    for (int step = 1; step <= k; step++)
    {
        for (int now = 1; now <= n; now++)
        {
            for (int nxt : g[now])
            {
                s[now][step].insert(s[nxt][step - 1].begin(), s[nxt][step - 1].end());
            }
        }
    }
    for (int now = 1; now <= n; now++)
    {
        for (int step = 1; step <= k; step++)
        {
            cout << s[now][step].size() << " ";
        }
        cout << endl;
    }
    return 0;
}