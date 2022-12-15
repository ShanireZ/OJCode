#include <iomanip>
#include <iostream>
using namespace std;
double a[1005];
int main() // 多项式加法
{
    int t = 2, cnt = 0;
    while (t--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            int exp;
            double coe;
            cin >> exp >> coe;
            a[exp] += coe;
        }
    }
    for (int i = 0; i <= 1000; i++)
    {
        cnt += (a[i] != 0);
    }
    cout << cnt;
    for (int i = 1000; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            cout << fixed << setprecision(1) << " " << i << " " << a[i];
        }
    }
    return 0;
}