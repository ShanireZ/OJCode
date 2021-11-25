#include <iostream>
#include <algorithm>
using namespace std;
int a[105], s[105];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int tot = s[j] - s[i - 1], cnt = j - i + 1;
            if (tot % cnt != 0)
            {
                continue;
            }
            int avg = tot / cnt;
            for (int k = i; k <= j; k++)
            {
                if (avg == a[k])
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}