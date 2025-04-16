#include <algorithm>
#include <iostream>
using namespace std;
int cnt[1005], n, s, m;
int main()
{
    cin >> n >> s >> m;
    cnt[s]++;
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            s = (s == n ? 1 : s + 1);
        }
        else
        {
            s = (s == 1 ? n : s - 1);
        }
        cnt[s]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t, score;
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            cin >> score;
            if (cnt[i] >= j)
            {
                ans += score;
            }
        }
    }
    cout << ans << endl;
    return 0;
}