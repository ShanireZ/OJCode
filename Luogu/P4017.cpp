#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[5005];
int ind[5005], outd[5005], ways[5005];
queue<int> q;
int main()
{
    int n, m, mod = 80112002;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        ind[a]++;
        outd[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
            ways[i] = 1;
        }
    }
    while (q.size() > 0)
    {
        int id = q.front();
        for (int i = 0; i < g[id].size(); i++)
        {
            int nid = g[id][i];
            ways[nid] = (ways[nid] + ways[id]) % mod;
            ind[nid]--;
            if (ind[nid] == 0)
            {
                q.push(nid);
            }
        }
        q.pop();
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (outd[i] == 0)
        {
            tot = (tot + ways[i]) % mod;
        }
    }
    cout << tot << endl;
    return 0;
}