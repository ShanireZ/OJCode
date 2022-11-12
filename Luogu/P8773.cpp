#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<long long, int> last;
int st[20][100005];
long long a[100005];
long long read();
int main()
{
    long long n = read(), m = read(), x = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        st[0][i] = last[a[i] ^ x];
        last[a[i]] = i;
    }
    for (int i = 1; i <= log2(n); i++)
    {
        int len = pow(2, i - 1);
        for (int j = 1; j + len * 2 - 1 <= n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + len]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        int x = log2(r - l + 1);
        int len = pow(2, x);
        printf((max(st[x][l], st[x][r - len + 1]) >= l) ? "yes\n" : "no\n");
    }
    return 0;
}
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