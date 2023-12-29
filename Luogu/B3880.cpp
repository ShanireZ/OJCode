#include <algorithm>
#include <iostream>
using namespace std;
long long len[10005], c[10005];
int main()
{
    long long n, m;
    cin >> n >> m >> len[1] >> c[1];
    for (int i = 2; i <= n; i++)
    {
        len[i] = (len[i - 1] * 37011 + 10193) % 10000 + 1;
        c[i] = (c[i - 1] * 73011 + 24793) % 100 + 1;
    }
    long long l = 1, r = 10000;
    while (l <= r)
    {
        long long mid = (l + r) / 2, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += len[i] / mid * c[i];
        }
        cnt >= m ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
// TAG: 二分答案