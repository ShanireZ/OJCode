#include <iostream>
#include <algorithm>
using namespace std;
int g[100005];
int prime[100005];
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    for (int i = a; i <= b; i++)
    {
        g[i] = i;
    }
    int tot = b - a + 1;
    for (int i = 2; i <= b / 2; i++)
    {
        if (prime[i] == 0) //i是质数
        {
            for (int j = 2; i * j <= b; j++)
            {
                prime[i * j] = 1;               //质数的倍数为合数
                if (i >= p && i * (j - 1) >= a) //当前合数和之前合数在a~b范围内可合并
                {
                    int gx = dfn(i * (j - 1)), gy = dfn(i * j);
                    if (gx != gy)
                    {
                        g[gy] = gx;
                        tot--;
                    }
                }
            }
        }
    }
    cout << tot;
    return 0;
}