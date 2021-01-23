#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int part[1005]; //每个瓶子的合并后的水量
int main()
{
    int n, k;
    cin >> n >> k;
    long long total = k;
    fill_n(part + 1, k, 1);
    //k个瓶子，最少水量为1，总计最小为k
    //我们先努力让k个瓶子的总水量接近n但不超过n
    //如果这时总水量正好为n，那么就不需要另行购买
    //如果不为n，那么现在让最小水量瓶子中的水量翻倍，这样就可让总水量超过n
    //翻倍后 新的总水量-n 即为所需新瓶子数量
    for (int i = 1; i <= k; i++)
    {
        while (total + part[i] <= n)
        {
            total += part[i];
            part[i] *= 2;
        }
        if (total == n)
        {
            cout << 0;
            return 0;
        }
    }
    int result = total + part[k] - n;
    cout << result;
    return 0;
}