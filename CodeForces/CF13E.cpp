#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int k[100005], nxt[100005], t[100005], p[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        nxt[i] = i + p[i], k[i] = (i - 1) / sz + 1;
    }
    for (int i = n; i >= 1; i--)
    {
        if (nxt[i] <= min(n, sz * k[i]))
        {
            t[i] = t[nxt[i]] + 1;
            nxt[i] = nxt[nxt[i]];
        }
        else
        {
            t[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int op, a, b;
        cin >> op >> a;
        if (op == 0)
        {
            cin >> b;
            p[a] = b;
            // 后方会引起前方变化,所以块内都需要更新
            for (int j = min(n, sz * k[a]); j > sz * (k[a] - 1); j--)
            {
                nxt[j] = j + p[j];
                if (nxt[j] <= min(n, sz * k[j]))
                {
                    t[j] = t[nxt[j]] + 1;
                    nxt[j] = nxt[nxt[j]];
                }
                else
                {
                    t[j] = 1;
                }
            }
        }
        else
        {
            int cnt = 0;
            while (nxt[a] <= n)
            {
                cnt += t[a], a = nxt[a];
            }
            while (a + p[a] <= n)
            {
                cnt++, a += p[a];
            }
            cout << a << " " << cnt + 1 << endl;
        }
    }
    return 0;
}
// TAG: 分块