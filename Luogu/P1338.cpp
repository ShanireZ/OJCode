#include <iostream>
#include <algorithm>
using namespace std;
struct Num
{
    int v, p;
};
Num a[50005];
bool cmp(Num x, Num y)
{
    return x.p < y.p;
}
int main()
{
    int n, m;
    cin >> n >> m;
    long long pos;
    for (long long i = 1; i <= n; i++)
    {
        long long tmp;
        tmp = i * (i - 1) / 2; //n个数中，i个数组成的倒叙能形成i * (i-1) / 2个逆序列
        if (tmp >= m)
        {
            pos = i; //一共pos个数需要打乱
            break;
        }
    }
    for (int i = 1; i <= n - pos; i++) //正常部分
    {
        a[i].v = i;
        a[i].p = i;
    }
    for (int i = n - pos + 1; i <= n; i++) //打乱部分
    {
        a[i].v = i;
        a[i].p = n - (i - (n - pos + 1));
    }
    long long total = pos * (pos - 1) / 2 - m; //需要打乱几个
    for (int i = 0; i < total; i++)            //从大到小依次移动打乱
    {
        int tmp;
        tmp = a[n - i].p;
        a[n - i].p = a[n - i - 1].p;
        a[n - i - 1].p = tmp;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].v << " ";
    }
    return 0;
}