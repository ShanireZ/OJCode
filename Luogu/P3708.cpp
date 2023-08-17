#include <algorithm>
#include <iostream>
using namespace std;
// https://research-1302056465.cos.ap-shanghai.myqcloud.com/research/Python/20230817140149.png
long long red[1000005];
int main()
{
    long long n, ans = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i; j <= 1000000; j += i)
        {
            red[j] += i;
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        ans = ans + n - red[i];
        cout << ans << " ";
    }
    return 0;
}
// TAG: 数学