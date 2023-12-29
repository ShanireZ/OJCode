#include <algorithm>
#include <iostream>
using namespace std;
long long p[1000005];
int main()
{
    int n, k;
    cin >> n >> k >> p[1];
    for (int i = 2; i <= k; i++)
    {
        p[i] = p[i - 1] + (p[i - 1] * 2357 + 137) % 10 + 1;
    }
    int l = 1, r = p[k] - p[1];
    while (l <= r)
    {
        int mid = (l + r) / 2, cnt = 1, pre = 1;
        for (int i = 2; i <= k; i++)
        {
            if (p[i] - p[pre] >= mid)
            {
                cnt++, pre = i;
            }
        }
        cnt >= n ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
// TAG: 二分答案