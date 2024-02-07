#include <algorithm>
#include <iostream>
using namespace std;
long long jc[1000005], tree[1000005], mod = 998244353, n, ans;
long long lowbit(long long x)
{
    return x & -x;
}
void edit(long long pos, long long k)
{
    while (pos <= n)
    {
        tree[pos] += k;
        pos += lowbit(pos);
    }
}
long long query(int pos)
{
    long long ans = 0;
    while (pos)
    {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main()
{
    cin >> n;
    jc[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        jc[i] = jc[i - 1] * i % mod;
        edit(i, 1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        long long x;
        cin >> x;
        edit(x, -1);
        ans = (ans + query(x) * jc[i] % mod) % mod;
    }
    cout << ans + 1 << endl;
    return 0;
}
// TAG: 康托展开 树状数组