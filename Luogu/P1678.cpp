#include <iostream>
#include <algorithm>
using namespace std;
int sch[100005];
int main()
{
    int m, n, tot = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> sch[i];
    }
    sort(sch + 1, sch + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int r = lower_bound(sch + 1, sch + 1 + m, x) - sch;
        int l = r;
        if (l != 1)
        {
            l--;
        }
        if (r > m || abs(sch[r] - x) > abs(x - sch[l]))
        {
            tot += abs(x - sch[l]);
        }
        else
        {
            tot += abs(sch[r] - x);
        }
    }
    cout << tot;
    return 0;
}