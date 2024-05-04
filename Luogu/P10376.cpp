#include <iostream>
using namespace std;
long long mod = 1e9 + 7, res[200005];
int a, b, c, n;
long long dfs(int now)
{
    if (now <= c) // 合理方案
    {
        return 1;
    }
    if (res[now] == 0) // 记忆化
    {
        res[now] = (res[now] + dfs(now - a) + dfs(now - b)) % mod;
    }
    return res[now];
}
int main()
{
    cin >> n >> a >> b >> c;
    dfs(n);
    cout << res[n] << endl;
    return 0;
}