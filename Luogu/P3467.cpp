#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
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
    int n = read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int d = read(), w = read();
        while (s.size() && s.top() > w)
        {
            s.pop();
        }
        if (s.empty() || s.top() < w)
        {
            s.push(w), ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}