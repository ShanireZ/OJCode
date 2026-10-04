#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int sum[1000005], f[1000005], v[1000005], n, k, ans;
vector<int> to[1000005];
void dfs(int now)
{
    vector<int> c;
    for (int nxt : to[now])
    {
        if (nxt == f[now])
        {
            continue;
        }
        f[nxt] = now;
        dfs(nxt);
        c.push_back(sum[nxt]);
    }
    sort(c.begin(), c.end());
    sum[now] = v[now];
    for (int x : c)
    {
        if (sum[now] + x > k)
        {
            ans++;
        }
        else
        {
            sum[now] += x;
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}