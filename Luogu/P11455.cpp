#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> p[100005];
int ans[100005], id[100005], pos;
int check(int len)
{
    int tot = 0;

    return tot;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int a = read();
        if (id[a] == 0)
        {
            id[a] = ++pos;
        }
        p[id[a]].emplace_back(i);
    }
    int fz = sqrt(n * log2(n));
    for (int k = 1; k <= fz; k++) // 枚举间隔小于等于fz的情况
    {
        for (int i = 1; i <= pos; i++)
        {
            auto it = p[i].begin();
            while (it != p[i].end())
            {
                ans[k]++, it = upper_bound(it, p[i].end(), *it + k);
            }
        }
    }
    for (int i = 1; i <= pos; i++) // 间隔大于fz时每个标记的组数会更少
    {
        ans[fz + 1]++;             // 前缀和优化
        for (int z = 1; true; z++) // 枚举组数
        {
            int l = fz + 1, r = n; // 二分间隔大小
            while (l <= r)
            {
                int mid = (l + r) / 2, cnt = 0;
                auto it = p[i].begin();
                while (it != p[i].end())
                {
                    cnt++, it = upper_bound(it, p[i].end(), *it + mid);
                }
                cnt <= z ? r = mid - 1 : l = mid + 1;
            }
            if (r < fz + 1)
            {
                break;
            }
            ans[fz + 1]++, ans[l]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > fz + 1)
        {
            ans[i] += ans[i - 1];
        }
        printf("%d\n", ans[i]);
    }
    return 0;
}