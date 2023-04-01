#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> m;
int prim[10005], ok[32005], pos;
int main()
{
    for (int i = 2; i <= 32000; i++)
    {
        if (ok[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; prim[j] * i <= 32000; j++)
        {
            ok[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        m.clear();
        int cnt = 0, ans = 1, a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a + 1; i <= b; i++)
        {
            int x = i;
            for (int j = 1; j <= pos && prim[j] <= sqrt(x); j++)
            {
                while (x % prim[j] == 0)
                {
                    m[prim[j]] += 1, x /= prim[j], cnt++;
                }
            }
            if (x > 1)
            {
                m[x] += 1, cnt++;
            }
        }
        for (int i = c + 1; i <= d && ans; i++)
        {
            int x = i;
            for (int j = 1; j <= pos && prim[j] <= sqrt(x) && ans; j++)
            {
                while (x % prim[j] == 0)
                {
                    if (m[prim[j]] == 0)
                    {
                        ans = 0;
                        break;
                    }
                    m[prim[j]] -= 1, x /= prim[j], cnt--;
                }
            }
            if (x > 1)
            {
                if (m[x] == 0)
                {
                    ans = 0;
                }
                m[x] -= 1, cnt--;
            }
        }
        if (cnt != 0)
        {
            ans = 0;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}