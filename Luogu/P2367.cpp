#include <iostream>
using namespace std;
int cf[5000005];
int main()
{
    int n, p, now, pre = 0, ans = 1e9;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        cf[i] = now - pre;
        pre = now;
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cf[x] += z;
        cf[y + 1] -= z;
    }
    now = 0;
    for (int i = 1; i <= n; i++)
    {
        now = cf[i] + now;
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}