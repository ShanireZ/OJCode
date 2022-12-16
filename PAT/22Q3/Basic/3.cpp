#include <iostream>
#include <queue>
#include <string>
using namespace std;
string all[10005];
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int minp = 0x3f3f3f3f, maxp = 0, ans = 0, cnt = 0, pos = 0;
    for (int i = 1; i <= n; i++)
    {
        string id;
        int p;
        cin >> id >> p;
        minp = min(minp, p), maxp = max(maxp, p);
        if (p >= a && p <= b)
        {
            cnt++;
            if (p >= ans)
            {
                pos = (p > ans) ? 1 : pos + 1;
                ans = p, all[pos] = id;
            }
        }
    }
    if (cnt)
    {
        cout << cnt << " " << ans << "\n";
        for (int i = 1; i <= pos; i++)
        {
            cout << all[i] << "\n";
        }
    }
    else
    {
        cout << minp << " " << maxp;
    }
    return 0;
}