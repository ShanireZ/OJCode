#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int nums[205][205];
int total[205][205];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nums[i][j];
        }
    }
    memset(total, 128, sizeof(total)); //无法到达的取值负无穷
    int start = n / 2 + 1;
    int end = n / 2 + 1;
    total[m + 1][start] = 0; //出发点
    for (int i = m; i >= 1; i--)
    {
        start = max(1, start - 1); //当前行有取值范围
        end = min(n, end + 1);
        for (int j = start; j <= end; j++)
        {
            int left = max(1, j - 1);
            int right = min(n, j + 1);
            int ans = max(total[i + 1][left], total[i + 1][right]);
            ans = max(ans, total[i + 1][j]);
            total[i][j] = ans + nums[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        if (total[1][i] > ans)
        {
            ans = total[1][i];
        }
    }
    cout << ans;
    return 0;
}