#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int p[200005], nxt[200005], t[200005], k[200005];
int main()
{
    int n, m;
    cin >> n;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        nxt[i] = i + p[i], k[i] = (i - 1) / sz + 1;
    }
    for (int i = n; i >= 1; i--)
    {
        t[i] = 1;
        if (nxt[i] <= min(n, k[i] * sz))
        {
            t[i] += t[nxt[i]];
            nxt[i] = nxt[nxt[i]];
        }
    }
    cin >> m;
    while (m--)
    {
        int op, a, b;
        cin >> op >> a;
        a++;
        if (op == 1)
        {
            int res = 0;
            while (a <= n)
            {
                res += t[a], a = nxt[a];
            }
            cout << res << endl;
        }
        else
        {
            cin >> b;
            p[a] = b;
            for (int i = min(n, k[a] * sz); i > (k[a] - 1) * sz; i--)
            {
                nxt[i] = i + p[i], t[i] = 1;
                if (nxt[i] <= min(n, k[i] * sz))
                {
                    t[i] += t[nxt[i]];
                    nxt[i] = nxt[nxt[i]];
                }
            }
        }
    }
    return 0;
}
// TAG: 分块