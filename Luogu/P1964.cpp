#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Good
{
    int a, b, c;
    string str;
};
Good gs[105];
struct Node
{
    int p, v;
};
vector<Node> ns;
int dp[30], pos;
int main()
{
    int m, n;
    cin >> m >> n;
    m = 21 - m;
    for (int i = 1; i <= n; i++) // 合并商品
    {
        int a, b, c, trig = 1;
        string str;
        cin >> a >> b >> c >> str;
        for (int i = 1; i <= pos; i++)
        {
            if (gs[i].str == str)
            {
                gs[i].a += a;
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            gs[++pos] = {a, b, c, str};
        }
    }
    for (int i = 1; i <= pos; i++) // 重构列举元素
    {
        int a = gs[i].a, b = gs[i].b, c = gs[i].c;
        if (a % c)
        {
            ns.push_back({1, a % c * b});
        }
        int x = a / c, base = 1;
        while (x >= base)
        {
            ns.push_back({base, c * b * base});
            x -= base;
            base *= 2;
        }
        if (x)
        {
            ns.push_back({x, c * b * x});
        }
    }
    for (int i = 0; i < ns.size(); i++)
    {
        for (int j = m; j >= ns[i].p; j--)
        {
            dp[j] = max(dp[j], dp[j - ns[i].p] + ns[i].v);
        }
    }
    cout << dp[m] << endl;
    return 0;
}