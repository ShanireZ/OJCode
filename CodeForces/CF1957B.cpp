#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int c[15];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(c, 0, sizeof(c));
        int n, k, x, pos = 0, trig = 0;
        cin >> n >> k;
        x = k;
        while (x)
        {
            c[++pos] = x % 2;
            x /= 2;
            if (c[pos] == 0)
            {
                trig++;
            }
        }
        if (n == 1 || trig == 0) // 只能分解为1个 或 k的二进制全为1,没法让1更多了
        {
            cout << k << " ";
            for (int i = 2; i <= n; i++)
            {
                cout << 0 << " ";
            }
            cout << "\n";
        }
        else // 可以让最高位的1消掉,这样后面就可以达成全是1了
        {
            x = pow(2, pos - 1) - 1;
            cout << x << " " << k - x << " ";
            for (int i = 3; i <= n; i++)
            {
                cout << 0 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}