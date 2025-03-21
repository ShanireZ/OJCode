#include <algorithm>
#include <bits/extc++.h>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
int T, k, n, s;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rk;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            rk.insert(i);
        }
        for (int i = 1; i <= k; i++)
        {
            cin >> s;
            int x = *rk.find_by_order(s);
            rk.erase(x);
            cout << x;
            if (i < k)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}