#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, k, ans;
vector<int> kz[100005], now;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int s, x;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            cin >> x;
            kz[i].push_back(x);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        vector<int> nxt;
        int a, tg = 0;
        cin >> a;
        if (now.size())
        {
            for (int xb : now)
            {
                int trig = 0;
                for (int x : kz[a])
                {
                    if (x == xb)
                    {
                        trig = 1;
                        break;
                    }
                }
                if (trig == 1)
                {
                    nxt.push_back(xb);
                    continue;
                }
                for (int x : kz[xb])
                {
                    if (x == a)
                    {
                        trig = 1;
                        break;
                    }
                }
                if (trig == 0)
                {
                    tg = 1;
                }
            }
        }
        now = nxt;
        if (now.size() || tg)
        {
            continue;
        }
        ans++;
        for (int x : kz[a])
        {
            now.push_back(x);
        }
    }
    cout << ans << endl;
    return 0;
}