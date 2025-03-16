#include <bits/extc++.h>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
long long jc[1000005], ans, mod = 998244353;
int main()
{
    int n;
    cin >> n;
    jc[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
        jc[i] = jc[i - 1] * i % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans = (ans + s.order_of_key(x) * jc[n - i] % mod) % mod;
        s.erase(x);
    }
    cout << ans + 1 << endl;
    return 0;
}