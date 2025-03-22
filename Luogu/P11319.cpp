#include <algorithm>
#include <bits/extc++.h>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
long long jc[300005], a[300005], n, ans, mod = 1e9 + 7;
int main()
{
    cin >> n;
    jc[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tr.insert(a[i]);
        jc[i] = jc[i - 1] * i % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += tr.order_of_key(a[i]) * jc[n - i] % mod;
        tr.erase(a[i]);
    }
    cout << (ans + 1) % mod << endl;
    return 0;
}