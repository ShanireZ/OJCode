#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int steps[100005] = {0};
    steps[0] = 1;
    //第0號臺階只有一種方案
    //第i號臺階的方案數=第i-1號臺階的方案數+...+第i-k號臺階的方案數
    //也就是說 第i號臺階的方案數= 其前側的k個臺階的方案數之和
    //如果前側臺階數不夠k個，那麼就加到第0號臺階為止
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            steps[i] += steps[i - j] % 100003;
            steps[i] %= 100003;
        }
    }
    cout << steps[n];
    return 0;
}