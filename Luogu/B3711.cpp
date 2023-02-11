#include <iostream>
using namespace std;
long long p10[20], nums[20], t;
int main()
{
    p10[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        p10[i] = p10[i - 1] * 10;
    }
    cin >> t;
    while (t--)
    {
        long long n, x, pos = 0, ok = 0;
        cin >> n;
        x = n;
        while (x)
        {
            nums[++pos] = x % 10, x /= 10;
        }
        if (n % 4 == 0)
        {
            ok = 1;
        }
        for (int l = pos; l >= 1; l--)
        {
            if (ok)
            {
                break;
            }
            for (int r = l; r >= 1; r--)
            {
                if (l == pos && r == 1) // 不能全删
                {
                    continue;
                }
                long long now = n / p10[l] * p10[r - 1] + n % p10[r - 1];
                if (now % 4 == 0)
                {
                    ok = 1;
                }
            }
        }
        cout << (ok == 1 ? "Yes" : "No") << "\n";
    }
    return 0;
}