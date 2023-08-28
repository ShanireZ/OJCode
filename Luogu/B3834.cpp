#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int cnt = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i * j == n)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
// TAG: 枚举 几何 GESP1