#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int col, t;
    char c1, c2;
};
Node ns[300];
int trans[300], mp[25][25];
string s;
bool cmpt(Node a, Node b)
{
    if (a.t == b.t)
    {
        return a.col < b.col;
    }
    return a.t > b.t;
}
bool cmpc(Node a, Node b)
{
    return a.col < b.col;
}
int f16to10(char x)
{
    int ans = 0;
    if (x <= '9' && x >= '0')
    {
        ans = x - '0';
    }
    else
    {
        ans = 10 + x - 'A';
    }
    return ans;
}
int main()
{
    int n;
    cin >> n >> s;
    int m = (int)s.size() / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0, pos = 1; pos <= m; j += 2, pos++)
        {
            int now = f16to10(s[j]) * 16 + f16to10(s[j + 1]);
            mp[i][pos] = now, ns[now].t++;
            ns[now].c1 = s[j], ns[now].c2 = s[j + 1], ns[now].col = now;
        }
        if (i != n)
        {
            cin >> s;
        }
    }
    sort(ns, ns + 256, cmpt);
    for (int i = 0; i < 16; i++)
    {
        cout << ns[i].c1 << ns[i].c2;
    }
    cout << endl;
    for (int i = 0; i < 256; i++)
    {
        int ans = 0, delta = abs(ns[0].col - i);
        for (int j = 1; j < 16; j++)
        {
            int dis = abs(ns[j].col - i);
            if (dis < delta) // 注意是编号小的优先
            {
                ans = j, delta = dis;
            }
        }
        trans[i] = ans;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (trans[mp[i][j]] < 10)
            {
                cout << trans[mp[i][j]];
            }
            else
            {
                cout << char(trans[mp[i][j]] - 10 + 'A');
            }
        }
        cout << endl;
    }
    return 0;
}
// TAG: 模拟 枚举 贪心