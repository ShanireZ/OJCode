#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int camp[100005];
int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> camp[i];
    }
    long long m, p1, s1, s2;
    cin >> m >> p1 >> s1 >> s2;
    camp[p1] += s1;

    long long total1 = 0, total2 = 0;
    for (int i = 1; i < m; i++)
    {
        total1 += (m - i) * camp[i];
    }
    for (int i = m + 1; i <= n; i++)
    {
        total2 += (i - m) * camp[i];
    }
    long long total = total1 - total2;

    long long ans = m;
    long long min_ans = abs(total);
    if (total < 0)
    {
        total = -total;
        for (int i = 1; i < m; i++)
        {
            long long tmp = abs((m - i) * s2 - total);
            if (tmp < min_ans)
            {
                min_ans = tmp;
                ans = i;
            }
        }
    }
    else if (total > 0)
    {
        for (int i = m + 1; i <= n; i++)
        {
            long long tmp = abs((i - m) * s2 - total);
            if (tmp < min_ans)
            {
                min_ans = tmp;
                ans = i;
            }
        }
    }
    cout << ans;
    return 0;
}