#include <iostream>
#include <cstring>
using namespace std;
int v[105];
int main()
{
    memset(v, -1, sizeof(v));
    int m, n, ans = 0;
    cin >> m >> n;
    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int trig = 0;
        for (int j = 1; j <= m; j++)
        {
            if (v[j] == x)
            {
                trig = 1;
                break;
            }
        }
        if (trig == 0)
        {
            v[now] = x;
            now++, ans++;
            if (now > m)
            {
                now = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}