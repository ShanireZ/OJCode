#include <algorithm>
#include <iostream>
using namespace std;
#define MX 30005
struct Enemy
{
    int a, b;
};
Enemy es[1005];
bool frd[MX][MX], noh[MX][MX];
int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    for (int i = 1; i <= p; i++)
    {
        int a, b;
        cin >> a >> b;
        frd[a][b] = frd[b][a] = 1; // 朋友关系
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        noh[a][b] = noh[b][a] = 1; // 不握手关系
        es[i].a = a, es[i].b = b;
    }
    int ans = n * (n - 1) / 2 - q; // 总对数 - 敌对不握手
    for (int i = 1; i <= q; i++)
    {
        int a = es[i].a, b = es[i].b; // a与b是敌人
        for (int j = 1; j <= n; j++)
        {
            if (noh[a][j] == 0 && frd[b][j] == 1 && frd[a][j] == 0) // b与j是朋友 a与j是陌生人且暂时不是不握手关系
            {
                noh[a][j] = noh[j][a] = 1, ans--;
            }
            if (noh[b][j] == 0 && frd[a][j] == 1 && frd[b][j] == 0) // a与j是朋友 b与j是陌生人且暂时不是不握手关系
            {
                noh[b][j] = noh[j][b] = 1, ans--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}