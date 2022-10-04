#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long a[300005], b[300005];
int main()
{
    memset(a, 0x3f, sizeof(a)), memset(b, 0x3f, sizeof(b));
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
    long long cnt = n * m - 1 - (n - 1) - (m - 1), ans = a[1] * (m - 1) + b[1] * (n - 1);
    long long ch = m - 1, cl = n - 1;
    int pa = 2, pb = 2;
    while (true)
    {
        if (a[pa] <= b[pb])
        {
            ans += a[pa] * ch, cnt -= ch;
            pa++, cl--;
        }
        else
        {
            ans += b[pb] * cl, cnt -= cl;
            pb++, ch--;
        }
        if (cnt == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}