#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
long long read()
{
    long long ans = 0;
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
unordered_map<long long, vector<int>> mp;
int a[500005];
int main()
{
    ios::sync_with_stdio(false);
    int n = read(), m = read(), ans = 1;
    for (int i = 1; i <= n; i++)
    {
        mp[read()].push_back(i);
    }
    a[0] = a[n + 1] = 1;
    for (int i = 1; i <= m; i++)
    {
        long long x = read();
        for (int j = 0; j < int(mp[x].size()); j++)
        {
            int pos = mp[x][j];
            if (a[pos - 1] + a[pos + 1] == 0)
            {
                ans++;
            }
            else if (a[pos - 1] + a[pos + 1] == 2)
            {
                ans--;
            }
            a[pos] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}