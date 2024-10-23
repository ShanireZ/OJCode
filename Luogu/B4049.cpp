#include <algorithm>
#include <iostream>
using namespace std;
int c[45], ids[45][105], sc[45][105], w[45][105], tot, cnt, n, xy;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= c[i]; j++)
        {
            cin >> ids[i][j];
        }
        sort(ids[i] + 1, ids[i] + c[i] + 1);
        for (int j = 1; j <= c[i]; j++)
        {
            cin >> sc[i][j];
        }
        for (int j = 1; j <= c[i]; j++)
        {
            cin >> w[i][j];
        }
    }
    cin >> xy;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(ids[i] + 1, ids[i] + c[i] + 1, xy) - ids[i]; // 学号的排名
        if (ids[i][pos] != xy)
        {
            continue;
        }
        pos = sc[i][pos]; // xy的参与度
        sort(sc[i] + 1, sc[i] + c[i] + 1);
        pos = upper_bound(sc[i] + 1, sc[i] + c[i] + 1, pos) - sc[i] - 1; // 参与度的排名,坑点,有参与度相同的
        cnt++, tot += w[i][c[i] - pos + 1];
    }
    cout << tot / cnt;
    if (tot % cnt != 0)
    {
        tot = tot % cnt;
        int g = __gcd(tot, cnt);
        cout << '+' << tot / g << '/' << cnt / g << endl;
    }
    return 0;
}