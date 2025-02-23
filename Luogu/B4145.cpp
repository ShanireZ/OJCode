#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y, k, ans = 0, cnt = 0;
    cin >> x >> y >> k;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            for (int m = 0; m <= k; m++)
            {
                int v = (i + j) ^ m;
                if (v == ans)
                {
                    cnt++;
                }
                else if (v > ans)
                {
                    ans = v, cnt = 1;
                }
            }
        }
    }
    cout << ans << endl
         << cnt << endl;
    return 0;
}