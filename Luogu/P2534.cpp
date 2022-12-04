#include <algorithm>
#include <iostream>
using namespace std;
int now[20], ls[20], mins, ok, n;
void dfs(int step, int pre)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (abs(now[i] - now[i + 1]) != 1);
    }
    if (cnt == 0)
    {
        ok = 1;
        return;
    }
    if (cnt + step > mins)
    {
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (i == pre)
        {
            continue;
        }
        reverse(now + 1, now + 1 + i);
        dfs(step + 1, i);
        reverse(now + 1, now + 1 + i);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> now[i];
        ls[i] = now[i];
    }
    sort(ls + 1, ls + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(ls + 1, ls + 1 + n, now[i]);
        now[i] = it - ls;
    }
    now[n + 1] = n + 1;
    while (1)
    {
        dfs(0, 0);
        if (ok)
        {
            cout << mins << endl;
            break;
        }
        mins++;
    }
    return 0;
}