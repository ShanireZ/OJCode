#include <algorithm>
#include <iostream>
using namespace std;
int cl[300005], cr[300005], a[300005], n, sl, sr, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cr[a[i]]++;
        if (cr[a[i]] == 1)
        {
            sr++;
        }
    }
    for (int i = 1; i < n; i++)
    {
        cr[a[i]]--;
        if (cr[a[i]] == 0)
        {
            sr--;
        }
        cl[a[i]]++;
        if (cl[a[i]] == 1)
        {
            sl++;
        }
        ans = max(ans, sl + sr);
    }
    cout << ans << endl;
    return 0;
}