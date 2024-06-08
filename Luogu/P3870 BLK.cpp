#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int len, op, tag;
};
Node ns[355];
int a[100005];
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int sz = sqrt(n), pos = 0;
    for (int i = 1; i <= n; i += sz)
    {
        ns[++pos].len = min(n - i + 1, sz);
    }
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 0)
        {
            while (l <= r)
            {
                int blk = (l - 1) / sz + 1;
                if (l % sz == 1 && r - l + 1 >= ns[blk].len)
                {
                    ns[blk].op = ns[blk].len - ns[blk].op;
                    ns[blk].tag = 1 - ns[blk].tag, l += sz;
                }
                else
                {
                    a[l] = 1 - a[l];
                    (ns[blk].tag == 0 && a[l] == 1) || (ns[blk].tag == 1 && a[l] == 0) ? ns[blk].op++ : ns[blk].op--;
                    l++;
                }
            }
        }
        else
        {
            int res = 0;
            while (l <= r)
            {
                int blk = (l - 1) / sz + 1;
                if (l % sz == 1 && r - l + 1 >= ns[blk].len)
                {
                    res += ns[blk].op, l += sz;
                }
                else
                {
                    res += (ns[blk].tag == 0 ? a[l] : 1 - a[l]);
                    l++;
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}