/*
    如果 n 为 4，那么 sum 是 a+3b+3c+d
    如果 n 为 5，那么 sum 是 a+4b+6c+4d+e
    如果 n 为 6，那么 sum 是 a+5b+10c+10d+5e+f
    组成 sum 的各项系数是个杨辉三角
*/
#include <iostream>
using namespace std;
int n, sum, trig, ans;
int num[15];
int usd[15];
int yh[15][15] = {
    {0},                                                      //杨辉三角表
    {0, 1},                                                   // N = 1
    {0, 1, 1},                                                // N = 2
    {0, 1, 2, 1},                                             // N = 3
    {0, 1, 3, 3, 1},                                          // N = 4
    {0, 1, 4, 6, 4, 1},                                       // N = 5
    {0, 1, 5, 10, 10, 5, 1},                                  // N = 6
    {0, 1, 6, 15, 20, 15, 6, 1},                              // N = 7
    {0, 1, 7, 21, 35, 35, 21, 7, 1},                          // N = 8
    {0, 1, 8, 28, 56, 70, 56, 28, 8, 1},                      // N = 9
    {0, 1, 9, 36, 84, 126, 126, 84, 36, 9, 1},                // N = 10
    {0, 1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1},       // N = 11
    {0, 1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1}}; // N = 12

void dfs(int step) //从小到大逐个填数
{
    if (step == n + 1 && sum == ans) //找到结果
    {
        trig = 1; //标记 已经找到答案
        for (int i = 1; i <= n; i++)
        {
            cout << num[i] << " ";
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (usd[i] == 0)
        {
            if (ans + yh[n][step] * i > sum) //剪枝 ans肯定会大于sum
            {
                return;
            }
            num[step] = i; //标记
            usd[i] = 1;
            ans += yh[n][step] * i;
            dfs(step + 1);
            if (trig) //剪枝 已经找到答案
            {
                return;
            }
            usd[i] = 0; //回溯
            ans -= yh[n][step] * i;
        }
    }
}
int main()
{
    cin >> n >> sum;
    dfs(1);
    return 0;
}