#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, q, rec[305], qst[305], anc[305][305];
vector<int> to[305];
void dfs(int now, int fa, int dp)
{
    rec[dp] = now;
    for (int nxt : to[now])
    {
        if (nxt != fa)
        {
            dfs(nxt, now, dp + 1);
        }
    }
    for (int i = 1; i <= dp; i++)
    {
        anc[now][rec[i]] = 1;
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        to[x + 1].push_back(i);
    }
    dfs(1, 0, 1);
    cin >> q;
    while (q--)
    {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            qst[i] = x + 1;
        }
        for (int i = n; i >= 1; i--)
        {
            int ok = 1;
            for (int j = 1; j <= m; j++)
            {
                if (anc[qst[j]][i] == 0)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << i - 1 << endl;
                break;
            }
        }
    }
    return 0;
}