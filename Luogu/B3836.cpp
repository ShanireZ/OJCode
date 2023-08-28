#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int x, y, z, n, m, cnt = 0;
    cin >> x >> y >> z >> n >> m;
    for (int i = 0; i <= min(n / x, m); i++)
    {
        for (int j = 0; j <= min(n / y, m - i); j++)
        {
            int k = (n - i * x - j * y) * z;
            if (i + j + k == m)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
// TAG: 模拟 枚举 GESP2