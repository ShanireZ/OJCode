#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<int, int> last;
int st[20][100005], a[100005], read();
int main()
{
    int n = read(), m = read(), x = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        st[0][i] = last[a[i] ^ x]; // 与a[i]异或结果为x的数,在i之前出现的位置
        last[a[i]] = i;
    }
    for (int i = 1; i <= log2(n); i++)
    {
        int len = pow(2, i - 1);
        for (int j = 1; j + len * 2 - 1 <= n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + len]); // 因为异或的数都在i之前出现,所以保证了位置小于等于R
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        int x = log2(r - l + 1);
        int len = pow(2, x);
        printf((max(st[x][l], st[x][r - len + 1]) >= l) ? "yes\n" : "no\n"); // 如果该位置大于等于L则满足题意
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