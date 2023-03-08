#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#define MX 1000005
set<int> noh[MX], frd[MX], emy[MX];
int main()
{
    long long n, p, q;
    cin >> n >> p >> q;
    for (int i = 1; i <= p; i++)
    {
        int u, v;
        cin >> u >> v;
        frd[u].insert(v), frd[v].insert(u);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        emy[u].insert(v), emy[v].insert(u);
        noh[u].insert(v), noh[v].insert(u);
    }
    long long ans = n * (n - 1) / 2 - q;
    for (int i = 1; i <= n; i++)
    {
        for (auto j = frd[i].begin(); j != frd[i].end(); j++)
        {
            int u = *j;
            for (auto k = emy[i].begin(); k != emy[i].end(); k++)
            {
                int v = *k;
                if (noh[u].find(v) == noh[u].end() && frd[u].find(v) == frd[u].end())
                {
                    ans--, noh[u].insert(v), noh[v].insert(u);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}