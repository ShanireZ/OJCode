#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int steps[100005] = {0};
    steps[0] = 1;
    //第0号台阶只有一种方案
    //第i号台阶的方案数=第i-1号台阶的方案数+...+第i-k号台阶的方案数
    //也就是说 第i号台阶的方案数= 其前侧的k个台阶的方案数之和
    //如果前侧台阶数不够k个，那么就加到第0号台阶为止
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