#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, y, m, d, h, f, y2, m2, d2, h2, f2, t[5005];
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int y)
{
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
    }
    sort(t + 1, t + n + 1);
    scanf("%d-%d-%d-%d:%d", &y, &m, &d, &h, &f);
    scanf("%d-%d-%d-%d:%d", &y2, &m2, &d2, &h2, &f2);
    long long tot = (f2 + h2 * 60) - (f + h * 60);
    while (y != y2 || m != m2 || d != d2)
    {
        tot += 1440;
        d++;
        if (d > days[m] + (check(y) && m == 2))
        {
            d = 1, m++;
        }
        if (m > 12)
        {
            m = 1, y++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (t[i] > tot)
        {
            break;
        }
        tot -= t[i], ans++;
    }
    printf("%d\n", ans);
    return 0;
}