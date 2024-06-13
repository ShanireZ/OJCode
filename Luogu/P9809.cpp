#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> s;
int res[555], n, sz = 548;
int main()
{
    cin >> n;
    for (int i = 1; i <= sz; i++)
    {
        res[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        char opt;
        int x;
        cin >> opt >> x;
        if (opt == 'A')
        {
            s.insert(x);
            for (int j = 1; j <= sz; j++)
            {
                res[j] = min(res[j], x % j); // 预处理小于sqrt(3e5)的答案
            }
        }
        else if (x <= sz)
        {
            cout << res[x] << '\n';
        }
        else
        {
            int ans = x, bs = 0; // 大于sqrt(3e5)的部分,暴力枚举每个x的倍数
            auto p = s.lower_bound(bs * x);
            while (p != s.end())
            {
                ans = min(ans, *p % x), bs++;
                p = s.lower_bound(bs * x);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
// TAG: 根号分治