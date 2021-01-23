#include <iostream>
using namespace std;
int n, k;
long long ans, mod = 1000000007;
void dfs(int step, long long cur)
{
    if (step > n)
    {
        if (cur % k == 0)
        {
            ans++;
        }
        return;
    }
    cur *= 10;
    for (int i = 1; i <= 6; i++)
    {
        cur += i;
        dfs(step + 1, cur);
        cur -= i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dfs(1, 0);
    cout << ans % mod;
    return 0;
}