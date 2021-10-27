#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
int read();
struct Plane
{
    int st, ed;
    bool operator<(const Plane ano) const
    {
        return st < ano.st;
    }
};
Plane pin[100005], pot[100005];                    //国内国际飞机
priority_queue<int, vector<int>, greater<int>> ok; //未使用的廊桥
int totin[100005], totot[100005];                  //廊桥接待的国内国际飞机数量
struct LQ
{
    int t, id;
    LQ(int T, int Id)
    {
        t = T, id = Id;
    }
    bool operator<(const LQ ano) const
    {
        return t > ano.t;
    }
};
priority_queue<LQ> usd; //已使用的廊桥

int main()
{
    int n = read(), m1 = read(), m2 = read();
    for (int i = 1; i <= m1; i++)
    {
        pin[i].st = read(), pin[i].ed = read();
    }
    sort(pin + 1, pin + 1 + m1);
    for (int i = 1; i <= m2; i++)
    {
        pot[i].st = read(), pot[i].ed = read();
    }
    sort(pot + 1, pot + 1 + m2);
    for (int i = 1; i <= n; i++) //队列初始化
    {
        ok.push(i);
    }
    for (int i = 1; i <= m1; i++) //只看国内
    {
        int now = pin[i].st;
        while (usd.size() && usd.top().t < now) //恢复已空出的廊桥
        {
            ok.push(usd.top().id);
            usd.pop();
        }
        if (ok.size() == 0)
        {
            continue;
        }
        int id = ok.top(); //飞机进入最前方廊桥
        ok.pop();
        usd.push(LQ(pin[i].ed, id));
        totin[id]++;
    }
    while (usd.size()) //队列初始化
    {
        ok.push(usd.top().id);
        usd.pop();
    }
    for (int i = 1; i <= m2; i++) //只看国外
    {
        int now = pot[i].st;
        while (usd.size() && usd.top().t < now) //恢复已空出的廊桥
        {
            ok.push(usd.top().id);
            usd.pop();
        }
        if (ok.size() == 0)
        {
            continue;
        }
        int id = ok.top(); //飞机进入最前方廊桥
        ok.pop();
        usd.push(LQ(pot[i].ed, id));
        totot[id]++;
    }
    for (int i = 1; i <= n; i++)
    {
        totin[i] += totin[i - 1];
        totot[i] += totot[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int tot = totin[i] + totot[n - i];
        ans = max(ans, tot);
    }
    printf("%d\n", ans);
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}