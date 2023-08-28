#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int x = i * i + j * j;
            int y = sqrt(x);
            if (y * y == x && y <= n)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
// TAG: 模拟 枚举 GESP2