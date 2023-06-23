#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
long long sum[500005];
deque<int> q;
long long read()
{
    long long ans = 0, tag = 1;
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
int main()
{
    long long n = read(), m = read(), ans = -1;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + read();
    }
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && sum[q.back()] >= sum[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        while (q.size() && q.front() < i - m)
        {
            q.pop_front();
        }
        ans = max(ans, sum[i] - sum[q.front()]);
    }
    printf("%lld\n", ans);
    return 0;
}