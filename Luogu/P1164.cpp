#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int foods[105];        //01背包问题
int check[105][10005]; //存储前a个物品总价等于b时方案数
int sum(int a, int b)
{
    if (check[a][b] == -1)
    {
        if (b == foods[a])
        {
            check[a][b] = sum(a - 1, b) + 1;
        }
        else if (b < foods[a])
        {
            check[a][b] = sum(a - 1, b);
        }
        else
        {
            check[a][b] = sum(a - 1, b) + sum(a - 1, b - foods[a]);
        }
    }
    return check[a][b];
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(check, -1, sizeof(check));
    for (int i = 1; i <= n; i++)
    {
        cin >> foods[i];
    }
    for (int i = 0; i <= m; i++)
    {
        check[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        check[i][0] = 0;
    }
    cout << sum(n, m);
    return 0;
}