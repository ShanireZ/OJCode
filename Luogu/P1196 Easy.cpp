#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 5
using namespace std;
int tops[MAXN];    //所在队伍队首
int ranks[MAXN];   //所在队伍中的名次
int lengths[MAXN]; //队伍长度
inline int find_top(int x)
{
    if (tops[x] == x)
    {
        return x;
    }
    else
    {
        int tmp = find_top(tops[x]); //先将其旧队链数据进行更新
        ranks[x] += ranks[tops[x]];  //更新其排名
        return tops[x] = tmp;        //更新其新队首
    }
}
int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i < MAXN; i++)
    {
        tops[i] = i;
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
            tops[top1] = top2;              //合并分组
            ranks[top1] += lengths[top2];   //队伍1的队首编号重排
            lengths[top2] += lengths[top1]; //队伍2的长度更新
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