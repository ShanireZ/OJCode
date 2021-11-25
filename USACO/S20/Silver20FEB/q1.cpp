#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, k;
int base[100005], a[100005], ans[100005];
void make(int x[100005], int y[100005]) //x按照y的规则交换 结果存在x中
{
    for (int i = 1; i <= n; i++)
    {
        ans[i] = x[y[i]];
    }
    memcpy(x + 1, ans + 1, sizeof(int) * n);
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) //初始化
    {
        a[i] = base[i] = i;
    }
    for (int i = 1; i <= m; i++) //第一轮交换后的结果作为base
    {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= (l + r) / 2; j++)
        {
            swap(base[j], base[l + r - j]);
        }
    }
    while (k) //根据k来矩阵加速交换
    {
        if (k & 1)
        {
            make(a, base);
        }
        k >>= 1;
        make(base, base);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}