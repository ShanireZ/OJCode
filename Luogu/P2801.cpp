#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int h[1000005], k[1000005], g[10000005], len[1005], tag[1005];
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
    int n = read(), m = read();
    int sz = sqrt(n), c = 0, gpos = 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = read();
        if (c == sz)
        {
            len[gpos++] = sz, c = 0;
        }
        g[i] = gpos, c++;
    }
    len[gpos] = c;
    for (int i = 1; i <= gpos; i++)
    {
        int st = (i - 1) * sz + 1;
        memcpy(k + st, h + st, len[i] * sizeof(int));
        sort(k + st, k + st + len[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        char opt;
        cin >> opt;
        int l = read(), r = read(), w = read();
        if (opt == 'M')
        {
            set<int> s;
            while (l <= r)
            {
                if (l % sz == 1 && r - l + 1 >= len[g[l]])
                {
                    tag[g[l]] += w;
                    l += len[g[l]];
                }
                else
                {
                    h[l] += w;
                    s.insert(g[l]); // 部分修改的块,需要用最新值重新排序
                    l++;
                }
            }
            for (auto x : s)
            {
                int st = (x - 1) * sz + 1;
                memcpy(k + st, h + st, len[x] * sizeof(int));
                sort(k + st, k + st + len[x]);
            }
        }
        else
        {
            int res = 0;
            while (l <= r)
            {
                if (l % sz == 1 && r - l + 1 >= len[g[l]])
                {
                    int p = lower_bound(k + l, k + l + len[g[l]], w - tag[g[l]]) - k;
                    res += l + len[g[l]] - p;
                    l += len[g[l]];
                }
                else
                {
                    res += (h[l] + tag[g[l]] >= w);
                    l++;
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
// TAG: 分块 二分