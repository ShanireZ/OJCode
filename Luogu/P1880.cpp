#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int nums[205];
int sums[205];
int max_s[205][205];
int min_s[205][205];

//递推公式为 f[i][j] = f[i][k] + f[k+1][j] + sum(i,j)
//其中k需要从i到j不断枚举，找到所有情况中的最值
//f[i][j]为从i到j的积分最值 sum为从i到j的总数量，用来进行两个分隔区间的合并加分
//i==j时，表示区间只有一个元素，所以无法合并返回0

int make_max(int l, int r)
{
    if (max_s[l][r] == 0 && l != r)
    {
        max_s[l][r] = -1;
        for (int i = l; i < r; i++)
        {
            max_s[l][r] = max(max_s[l][r], make_max(l, i) + make_max(i + 1, r) + sums[r] - sums[l - 1]);
        }
    }
    return max_s[l][r];
}
int make_min(int l, int r)
{
    if (min_s[l][r] == 0 && l != r)
    {
        min_s[l][r] = 0x3f3f3f3f;
        for (int i = l; i < r; i++)
        {
            min_s[l][r] = min(min_s[l][r], make_min(l, i) + make_min(i + 1, r) + sums[r] - sums[l - 1]);
        }
    }
    return min_s[l][r];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        nums[i + n] = nums[i]; //为环状分布，所以得将其复制延长
    }
    for (int i = 1; i <= n * 2; i++)
    {
        sums[i] = nums[i] + sums[i - 1]; //计算从1至i的总数量
    }
    make_min(1, n * 2);
    make_max(1, n * 2);
    int ans_min = 0x3f3f3f3f, ans_max = -1;
    //进行合理区间的查找，因为长度只能为n
    for (int i = 1; i <= n; i++)
    {
        ans_min = min(ans_min, min_s[i][n + i - 1]);
        ans_max = max(ans_max, max_s[i][n + i - 1]);
    }
    cout << ans_min << endl
         << ans_max;
    return 0;
}