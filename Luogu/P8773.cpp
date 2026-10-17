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
        st[i][0] = last[a[i] ^ x]; // 與a[i]異或結果為x的數,在i之前出現的位置
        last[a[i]] = i;
    }
    for (int j = 1; j <= log2(n); j++)
    {
        int len = pow(2, j - 1);
        for (int i = 1; i + len * 2 - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + len][j - 1]); // 因為異或的數都在i之前出現,所以保證了位置小於等於R
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        int x = log2(r - l + 1);
        int len = pow(2, x);
        printf((max(st[l][x], st[r - len + 1][x]) >= l) ? "yes\n" : "no\n"); // 如果該位置大於等於L則滿足題意
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