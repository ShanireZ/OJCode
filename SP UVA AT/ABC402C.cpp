#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> rel[300005];
int n, m, res, cnt[300005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int k, a;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a;
            rel[a].emplace_back(i);
        }
        cnt[i] = k;
    }
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        for (int x : rel[b])
        {
            cnt[x]--;
            res += (cnt[x] == 0);
        }
        cout << res << endl;
    }
    return 0;
}