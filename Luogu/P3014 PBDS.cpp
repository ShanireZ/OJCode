#include <algorithm>
#include <bits/extc++.h>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
long long jc[25], a, n, k, ans;
int main()
{
    cin >> n >> k;
    jc[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        jc[i] = jc[i - 1] * i;
    }
    while (k--)
    {
        for (int i = 1; i <= n; i++)
        {
            tr.insert(i);
        }
        char op;
        cin >> op;
        if (op == 'P')
        {
            long long rk;
            cin >> rk;
            rk -= 1;
            for (int i = 1; i <= n; i++)
            {
                int x = *tr.find_by_order(rk / jc[n - i]);
                tr.erase(x), rk %= jc[n - i];
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            long long res = 1;
            for (int i = 1; i <= n; i++)
            {
                cin >> a;
                res += tr.order_of_key(a) * jc[n - i];
                tr.erase(a);
            }
            cout << res << endl;
        }
    }
    return 0;
}