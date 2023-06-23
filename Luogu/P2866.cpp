#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int h[80005], ans[80005];
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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
    for (int i = 1; i <= n; i++)
    {
        h[i] = read();
        while (s.size() && h[s.top()] <= h[i])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            tot += 0ll + n - i;
        }
        else
        {
            tot += 0ll + (ans[i] - 1) - i;
        }
    }
    printf("%lld\n", tot);
    return 0;
}