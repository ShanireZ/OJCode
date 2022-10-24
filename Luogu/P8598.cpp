#include <iostream>
using namespace std;
int cnt[100005];
int main()
{
    int n, x, mn = 1e8, mx = 0;
    cin >> n;
    while (cin >> x)
    {
        cnt[x]++;
        mx = max(mx, x), mn = min(mn, x);
    }
    int ans1, ans2;
    for (int i = mn; i <= mx; i++)
    {
        if (cnt[i] == 0)
        {
            ans1 = i;
        }
        if (cnt[i] == 2)
        {
            ans2 = i;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}