#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int cows[105];          //每头奶牛的初始牛棚
vector<int> ways[1005]; //每个农场的所有路
int farm[1005];         //该农场能被几头奶牛到达
int vis[1005];          //该农场当前是否被遍历过
void dfs(int x)
{
    for (int i = 0; i < ways[x].size(); i++)
    {
        int nid = ways[x][i];
        if (vis[nid] == 0)
        {
            vis[nid] = 1;
            farm[nid]++;
            dfs(nid);
        }
    }
}
int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
    {
        cin >> cows[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        ways[a].push_back(b);
    }
    for (int i = 1; i <= k; i++)
    {
        memset(vis, 0, sizeof(vis));
        farm[cows[i]]++;
        vis[cows[i]] = 1;
        dfs(cows[i]);
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (farm[i] == k)
        {
            tot++;
        }
    }
    cout << tot;
    return 0;
}