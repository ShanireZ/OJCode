#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 30005
using namespace std;
int tops[MAXN];    //队首
int rears[MAXN];   //队尾
int ranks[MAXN];   //所在队伍排名
int lengths[MAXN]; //队伍长度
int pres[MAXN];    //上一个元素
inline int find_top(int x)
{
    if (tops[x] == x)
    {
        return x;
    }
    else
    {
        return tops[x] = find_top(tops[x]);
    }
}
inline int find_rear(int x)
{
    if (rears[x] == x)
    {
        return x;
    }
    else
    {
        return rears[x] = find_rear(rears[x]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i < MAXN; i++)
    {
        tops[i] = i;
        rears[i] = i;
        ranks[i] = 1;
        lengths[i] = 1;
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        char type;
        int origin, target;
        cin >> type >> origin >> target;
        int top1 = find_top(origin);
        int top2 = find_top(target);
        if (type == 'M') //合并
        {
            int rear1 = find_rear(origin);
            int rear2 = find_rear(target);
            tops[top1] = top2; //合并分组
            rears[rear2] = rear1;
            pres[top1] = rear2; //队伍1的队首接在队伍2的队尾
            lengths[top2] += lengths[top1];
            int tmp = 0; //重排编号
            for (int j = rear1; j != rear2; j = pres[j])
            {
                ranks[j] = lengths[top2] - tmp;
                tmp++;
            }
        }
        else //查询
        {
            if (top1 != top2)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << abs(ranks[origin] - ranks[target]) - 1 << '\n';
            }
        }
    }
    return 0;
}