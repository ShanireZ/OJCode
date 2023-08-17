#include <algorithm>
#include <iostream>
using namespace std;
long long f[25];
int main()
{
    int n;
    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] += f[j] * f[i - 1 - j];
        }
    }
    cout << f[n] << "\n";
    return 0;
}
// TAG: 卡特兰数 栈 数学