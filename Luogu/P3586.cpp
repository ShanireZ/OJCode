#include <cstdio>
#include <algorithm>
using namespace std;
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
//cnt統計個數 sum統計和 all離散化 nums每個位置上的數字(離散後)
long long cnt[1000005], sum[1000005], all[1000005], nums[1000005];
int n, m, p;
struct Op
{
    int type;
    long long a, b;
};
Op ops[1000005];
int lowbit(int x)
{
    return x & -x;
}
void editc(int now, long long add)
{
    while (now <= p)
    {
        cnt[now] += add;
        now += lowbit(now);
    }
}
void edits(int now, long long add)
{
    while (now <= p)
    {
        sum[now] += add;
        now += lowbit(now);
    }
}
long long queryc(int now)
{
    long long ans = 0;
    while (now)
    {
        ans += cnt[now];
        now -= lowbit(now);
    }
    return ans;
}
long long querys(int now)
{
    long long ans = 0;
    while (now)
    {
        ans += sum[now];
        now -= lowbit(now);
    }
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        char ch = getchar();
        while (ch != 'U' && ch != 'Z')
        {
            ch = getchar();
        }
        if (ch == 'Z')
        {
            ops[i].type = 2;
        }
        ops[i].a = read(), ops[i].b = read();
        all[++p] = ops[i].b;
    }
    sort(all + 1, all + 1 + p);
    p = unique(all + 1, all + 1 + p) - (all + 1);
    for (int i = 1; i <= m; i++)
    {
        if (ops[i].type == 0) //修改
        {
            long long now = lower_bound(all + 1, all + 1 + p, ops[i].b) - all;
            long long pre = nums[ops[i].a];
            nums[ops[i].a] = now;
            if (pre != 0)
            {
                editc(pre, -1);
                edits(pre, -all[pre]);
            }
            editc(now, 1);
            edits(now, all[now]);
        }
        else
        {
            long long s = lower_bound(all + 1, all + 1 + p, ops[i].b) - all;
            //每輪需求總數-每輪固定供給(大於等於s的個數)=每輪仍缺的靈活供給個數
            long long c = ops[i].a - (queryc(p) - queryc(s - 1));
            if (querys(s - 1) < c * ops[i].b) //如果靈活供給部分量不夠
            {
                printf("NIE\n");
            }
            else
            {
                printf("TAK\n");
            }
        }
    }
    return 0;
}