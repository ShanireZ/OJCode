#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
vector<int> cnt[7];
int main()
{
    int n = read(), qz = 0, x;
    //如果要求区间[x,y]的和 % 7 == 0
    //那么区间[x,y]中的前缀和 qz[y] % 7 - qz[x-1] % 7 == 0
    //也就是说两个前缀和%7余数相同
    //最大区间必然是两个%7余数相同的区间
    //cnt[i]表示余数为i的位置有哪些
    for (int i = 1; i <= n; i++)
    {
        x = read();
        qz = (qz + x) % 7;
        cnt[qz].push_back(i);
    }
    int maxsz = 0;
    for (int i = 0; i < 7; i++)
    {
        if (cnt[i].size() > 1)
        {
            int sz = cnt[i][cnt[i].size() - 1] - cnt[i][0];
            maxsz = max(maxsz, sz);
        }
    }
    printf("%d", maxsz);
    return 0;
}