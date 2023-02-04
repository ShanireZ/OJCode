#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<int, int> last;
int st[100005][20], a[100005], read();
int main()
{
    int n = read(), m = read(), x = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        st[i][0] = last[a[i] ^ x]; // 与a[i]异或结果为x的数,在i之前出现的位置
        last[a[i]] = i;
    }
    for (int j = 1; j <= log2(n); j++)
    {
        int len = pow(2, j - 1);
        for (int i = 1; i + len * 2 - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + len][j - 1]); // 因为异或的数都在i之前出现,所以保证了位置小于等于R
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        int x = log2(r - l + 1);
        int len = pow(2, x);
        printf((max(st[l][x], st[r - len + 1][x]) >= l) ? "yes\n" : "no\n"); // 如果该位置大于等于L则满足题意
    }
    return 0;
}
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