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
        if (prime[i] == 0) //i是質數
        {
            for (int j = 2; i * j <= b; j++)
            {
                prime[i * j] = 1;               //質數的倍數為合數
                if (i >= p && i * (j - 1) >= a) //當前合數和之前合數在a~b範圍內可合併
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