#include <iostream>
#include <cstdio>
using namespace std;
int link[105][105];  //从第i号工厂出发能直接到达那些工厂
int check[105][105]; //从第i号工厂出发，能否到达第j号工厂
void make(int start, int cur)
{
    for (int i = 1; i <= link[cur][0]; i++)
    {
        if (check[start][link[cur][i]] == 0)
        {
            check[start][link[cur][i]] = 1;
            make(start, link[cur][i]);
        }
    }
}
int main()
{
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        link[a][++link[a][0]] = b;
    }
    for (int i = 1; i <= n; i++)
    {
        check[i][i] = 1;
        make(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int total = 0;
        for (int j = 1; j <= n; j++)
        {
            total += check[j][i];
        }
        if (total == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}