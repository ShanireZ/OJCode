#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
struct Num
{
    int p, val;
};
deque<Num> mx[1005], mn[1005], qmx, qmn;
int v[1005][1005], amx[1005][1005], amn[1005][1005];
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    int a = read(), b = read(), n = read(), ans = 1e9;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            v[i][j] = read();
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j < n; j++)
        {
            while (mx[i].size() && mx[i].back().val <= v[i][j])
            {
                mx[i].pop_back();
            }
            mx[i].push_back((Num){j, v[i][j]});
            while (mn[i].size() && mn[i].back().val >= v[i][j])
            {
                mn[i].pop_back();
            }
            mn[i].push_back((Num){j, v[i][j]});
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = n; j <= b; j++)
        {
            while (mx[i].size() && mx[i].back().val <= v[i][j])
            {
                mx[i].pop_back();
            }
            mx[i].push_back((Num){j, v[i][j]});
            while (mn[i].size() && mn[i].back().val >= v[i][j])
            {
                mn[i].pop_back();
            }
            mn[i].push_back((Num){j, v[i][j]});
            if (mx[i].front().p <= j - n)
            {
                mx[i].pop_front();
            }
            if (mn[i].front().p <= j - n)
            {
                mn[i].pop_front();
            }
            amx[i][j] = mx[i].front().val;
            amn[i][j] = mn[i].front().val;
        }
    }
    for (int j = n; j <= b; j++)
    {
        qmx.clear(), qmn.clear();
        for (int i = 1; i < n; i++)
        {
            while (qmx.size() && qmx.back().val <= amx[i][j])
            {
                qmx.pop_back();
            }
            qmx.push_back((Num){i, amx[i][j]});
            while (qmn.size() && qmn.back().val >= amn[i][j])
            {
                qmn.pop_back();
            }
            qmn.push_back((Num){i, amn[i][j]});
        }
        for (int i = n; i <= a; i++)
        {
            while (qmx.size() && qmx.back().val <= amx[i][j])
            {
                qmx.pop_back();
            }
            qmx.push_back((Num){i, amx[i][j]});
            while (qmn.size() && qmn.back().val >= amn[i][j])
            {
                qmn.pop_back();
            }
            qmn.push_back((Num){i, amn[i][j]});
            if (qmx.front().p <= i - n)
            {
                qmx.pop_front();
            }
            if (qmn.front().p <= i - n)
            {
                qmn.pop_front();
            }
            ans = min(ans, qmx.front().val - qmn.front().val);
        }
    }
    printf("%d\n", ans);
    return 0;
}