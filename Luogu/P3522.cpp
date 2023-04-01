#include <iostream>
using namespace std;
struct Node
{
    int lim, pos;
};
Node ns[1000005];
int read();
int main()
{
    int n = read(), st = 1, ed = 0, ans = 1, now = 1;
    for (int i = 1; i <= n; i++)
    {
        int l = read(), r = read();
        while (ed >= st && l > ns[ed].lim)
        {
            ed--;
        }
        ns[++ed].lim = l, ns[ed].pos = i;
        while (ed >= st && r < ns[st].lim)
        {
            st++;
            now = ns[st].pos;
        }
        ans = max(ans, i - now + 1);
    }
    printf("%d\n", ans);
    return 0;
}
int read()
{
    int ans = 0, tag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        tag = (ch == '-') ? -1 : 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * tag;
}
// TAG: 单调队列