#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int items[35];        //01背包问题
int check[35][20005]; //存储前a个物体总体积不超过b时，最大的总体积
int sum(int a, int b)
{
    if (check[a][b] == -1)
    {
        if (b < items[a])
        {
            check[a][b] = sum(a - 1, b);
        }
        else
        {
            check[a][b] = max(sum(a - 1, b), sum(a - 1, b - items[a]) + items[a]);
        }
    }
    return check[a][b];
}

int main()
{
    int v, n;
    cin >> v >> n;
    memset(check, -1, sizeof(check));
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i];
    }
    for (int i = 0; i <= v; i++)
    {
        check[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        check[i][0] = 0;
    }
    cout << v - sum(n, v);
    return 0;
}