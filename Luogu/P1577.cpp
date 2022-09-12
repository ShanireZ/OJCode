#include <iomanip>
#include <iostream>
using namespace std;
int len[10005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        double x;
        cin >> x;
        len[i] = x * 1000;
    }
    int l = 1, r = 100000000;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += len[i] / mid;
        }
        if (cnt >= k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << fixed << setprecision(3) << r / 1000.0 << endl; // 最后两个测试点有精度问题
    return 0;
}