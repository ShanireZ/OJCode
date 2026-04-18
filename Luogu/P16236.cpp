#include <algorithm>
#include <iostream>
using namespace std;
long long n, ans, now, l[100005], q[100005], a[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'L')
        {
            a[i] = a[i - 1];
            l[i] = l[i - 1] + 1;
            q[i] = q[i - 1];
        }
        else if (c == 'Q')
        {
            a[i] = a[i - 1];
            l[i] = l[i - 1];
            q[i] = q[i - 1] + 1;
            now += l[i] + a[i];
        }
        else
        {
            a[i] = a[i - 1] + 1;
            l[i] = l[i - 1];
            q[i] = q[i - 1];
        }
    }
    ans = now; // 全填L
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == a[i - 1] + 1)
        {
            now += (l[i - 1] + a[i - 1]) - (q[n] - q[i]) - (a[n] - a[i]); // 下标i处L->Q,导致后方原有配对失效，而前方则新增配对
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}