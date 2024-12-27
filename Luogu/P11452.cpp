#include <algorithm>
#include <iostream>
using namespace std;
long long a[500005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        int chs = n - n / 2 - 1;
        long long res = 0;
        for (int i = 0; i <= chs; i++) // 枚举Elise的所有选择
        {
            long long l = a[i], r = a[n] - a[n - chs + i];
            res = max(res, l + r);
        }
        cout << a[n] - res << " " << res << endl;
    }
    return 0;
}