#include <iostream>
using namespace std;
int add[300005], red[300005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        add[l]++, red[r + 1]++;
    }
    long long ans = 0, now = 0, cnt = 0;
    for (int i = 1; i <= 300000; i++)
    {
        if (add[i] || red[i])
        {
            ans = max(ans, (i - 1 - now) * cnt);
            cnt = cnt + add[i] - red[i];
            now = i;
        }
    }
    cout << ans << endl;
    return 0;
}