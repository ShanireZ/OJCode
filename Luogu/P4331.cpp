#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q;
int a[1000005];
int read()
{
    int ans = 0;
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
int main()
{
    int n = read();
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read() - i;
        q.push(x);
        if (x < q.top())
        {
            ans += q.top() - x;
            q.pop(), q.push(x);
        }
        a[i] = q.top();
    }
    printf("%lld\n", ans);
    for (int i = n - 1; i >= 1; i--)
    {
        a[i] = min(a[i], a[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i] + i);
    }
    return 0;
}