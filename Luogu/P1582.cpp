#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int part[1005]; //每個瓶子的合併後的水量
int main()
{
    int n, k;
    cin >> n >> k;
    long long total = k;
    fill_n(part + 1, k, 1);
    //k個瓶子，最少水量為1，總計最小為k
    //我們先努力讓k個瓶子的總水量接近n但不超過n
    //如果這時總水量正好為n，那麼就不需要另行購買
    //如果不為n，那麼現在讓最小水量瓶子中的水量翻倍，這樣就可讓總水量超過n
    //翻倍後 新的總水量-n 即為所需新瓶子數量
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