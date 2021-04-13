#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> w, c;
int read();
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        w.push_back(read());
    }
    for (int i = 1; i <= m; i++)
    {
        c.push_back(read());
    }
    sort(w.begin(), w.end());
    sort(c.begin(), c.end());
    int ans = 0;
    for (int i = 0; i < m && w.size(); i++)
    {
        vector<int>::iterator it = lower_bound(w.begin(), w.end(), c[i]);
        if (it != w.end())
        {
            ans++;
            w.erase(it);
        }
    }
    printf("%d", ans);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}