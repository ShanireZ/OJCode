#include <algorithm>
#include <iostream>
using namespace std;
long long l, r, ans[5], nums[20], area[20], pw[20][20];
void makeans(int op, long long x)
{
    int pos = 0;
    while (x)
    {
        nums[++pos] = x % 10;
        x /= 10;
    }
    reverse(nums + 1, nums + pos + 1);
    for (int i = 1; i < pos; i++)
    {
        ans[op] += area[i];
    }
    for (int i = 1; i <= pos; i++)
    {
        if (i == 1)
        {
            for (int j = 1; j < nums[i]; j++)
            {
                ans[op] += pw[pos - i][j];
            }
        }
        else if (nums[1] - 1 >= nums[i])
        {
            ans[op] += pw[pos - i][nums[1]] * nums[i];
        }
        else
        {
            ans[op] += pw[pos - i + 1][nums[1]];
            return;
        }
    }
    ans[op]++;
}
int main()
{
    fill(pw[0], pw[0] + 20, 1);
    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            pw[i][j] = pw[i - 1][j] * j;
            area[i] += pw[i - 1][j]; // 统计i位数共有多少蛇数
        }
    }
    cin >> l >> r;
    makeans(1, l - 1), makeans(2, r);
    cout << ans[2] - ans[1] << endl;
    return 0;
}