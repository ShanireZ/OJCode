#include <iomanip>
#include <iostream>
using namespace std;
double coe[5][1005], ans[2005];
int main() // 多项式乘法
{
    for (int t = 1; t <= 2; t++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int exp;
            cin >> exp;
            cin >> coe[t][exp];
        }
    }
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            ans[i + j] += coe[1][i] * coe[2][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 2000; i++)
    {
        cnt += (ans[i] != 0);
    }
    cout << cnt;
    for (int i = 2000; i >= 0; i--)
    {
        if (ans[i] != 0)
        {
            cout << fixed << setprecision(1) << " " << i << " " << ans[i];
        }
    }
    return 0;
}