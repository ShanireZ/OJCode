#include <cstdio>
using namespace std;
unsigned long long read(); //快讀
int ani[70];               //二進制每位是否已經存在1
int no[70];                //二進制每位是否必然是0
int main()
{
    int n = read(), m = read(), c = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        unsigned long long id = read();
        int pos = 0;
        while (id)
        {
            int r = id % 2;
            if (r == 1)
            {
                ani[pos] = 1;
            }
            pos++;
            id /= 2;
        }
    }
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int p = read(), q = read();
        //統計有多少位必須是0
        if (ani[p] == 0 && no[p] == 0) //該位沒有1 說明此飼料不購買 此位必定是0
        {
            tot++;
            no[p] = 1;
        }
    }
    //總位數-必為0的位數=可10隨意的位數
    k -= tot;
    //(2^可10隨意的位數)-n=還可添加的數量
    if (k == 64)
    {
        if (n == 0)
        {
            printf("18446744073709551616");
        }
        else
        {
            unsigned long long ans = 18446744073709551615ull;
            ans = ans - n + 1;
            printf("%llu", ans);
        }
    }
    else
    {
        unsigned long long ans = (1ull << k) - n;
        printf("%llu", ans);
    }
    return 0;
}
unsigned long long read() //快讀
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    unsigned long long t = 1, n = 0;
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