#include <algorithm>
#include <iostream>
using namespace std;
int nums[105];
int main()
{
    long long n, q, p, ans = 0;
    cin >> n >> q;
    for (int i = 1; n; i++)
    {
        nums[i] = n % 2;
        n /= 2;
    }
    while (q--)
    {
        cin >> p;
        if (nums[p] == 1)
        {
            continue;
        }
        long long now = 0;
        for (int i = p; i >= 1; i--)
        {
            now = now * 2 + nums[i];
            nums[i] = 0;
        }
        nums[p] = 1;
        ans += (1ll << (p - 1)) - now;
    }
    cout << ans << endl;
    return 0;
}