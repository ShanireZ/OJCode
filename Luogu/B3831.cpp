#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
long long n, x, y, p, q, cnt[1005], dis[1005];
stack<long long> s;
int main()
{
    cin >> n >> x >> y >> p;
    for (long long i = 0; i < p; i++)
    {
        if (dis[i] == 0)
        {
            long long step = 1, now = (i * x + y) % p;
            s.push(i);
            while (i != now)
            {
                step++, now = (now * x + y) % p, s.push(i);
            }
            while (s.size())
            {
                dis[s.top()] = step, s.pop();
            }
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        if (a >= p)
        {
            continue;
        }
        cnt[dis[a % p]]++;
    }
    cin >> q;
    while (q--)
    {
        long long k, ans = 0;
        cin >> k;
        for (long long i = 1; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                ans += cnt[i];
                if (k / i != i)
                {
                    ans += cnt[k / i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}