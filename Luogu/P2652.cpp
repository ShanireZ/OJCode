#include <algorithm>
#include <iostream>
using namespace std;
struct Card
{
    int c, v;
    bool operator<(const Card na) const
    {
        return (c == na.c) ? v < na.v : c < na.c;
    }
};
Card cs[100005];
int s[100005], pos, ans = 1;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cs[i].c >> cs[i].v;
    }
    sort(cs + 1, cs + 1 + n);
    int sz = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cs[i].v != cs[i - 1].v || cs[i].c != cs[i - 1].c)
        {
            cs[++sz] = cs[i];
        }
    }
    for (int i = 1; i <= sz; i++) //枚举L
    {
        for (int j = i + 1; j <= sz && cs[j].c == cs[i].c; j++) //枚举R
        {
            if (n >= cs[j].v - cs[i].v + 1)
            {
                ans = max(ans, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}