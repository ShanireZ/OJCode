#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Item
{
    int v, p, mul;
};
Item items[30];       //01背包问题
int check[30][30005]; //存储前a个物品总价不超过b时，最大的积
int sum(int a, int b)
{
    if (check[a][b] == -1)
    {
        if (b < items[a].v)
        {
            check[a][b] = sum(a - 1, b);
        }
        else
        {
            check[a][b] = max(sum(a - 1, b), sum(a - 1, b - items[a].v) + items[a].mul);
        }
    }
    return check[a][b];
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(check, -1, sizeof(check));
    for (int i = 1; i <= m; i++)
    {
        cin >> items[i].v >> items[i].p;
        items[i].mul = items[i].v * items[i].p;
    }
    for (int i = 0; i <= n; i++)
    {
        check[0][i] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        check[i][0] = 0;
    }
    cout << sum(m, n);
    return 0;
}