#include <algorithm>
#include <iostream>
using namespace std;
long long ys[32005], n, T;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int pos = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ys[++pos] = i;
                if (i * i != n)
                {
                    ys[++pos] = n / i;
                }
            }
        }
        sort(ys + 1, ys + pos + 1);
        ys[pos + 1] = ys[pos] + 1;
        long long ans = 0;
        for (int i = 1; i <= pos; i++)
        {
            ans += ys[i] * (ys[pos - i + 2] - ys[pos - i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}