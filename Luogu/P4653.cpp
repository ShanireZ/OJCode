#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
double a[100005], b[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + 1 + n, greater<double>());
    sort(b + 1, b + 1 + n, greater<double>());
    int pa = 1, pb = 1, cnt = 0;
    double tota = 0, totb = 0, ans = 0;
    while (cnt < n * 2)
    {
        if (pb > n || (pa <= n && tota < totb))
        {
            tota += a[pa];
            pa++;
        }
        else
        {
            totb += b[pb];
            pb++;
        }
        cnt++;
        ans = max(ans, min(tota, totb) - cnt);
    }
    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}
// TAG: 贪心 双指针