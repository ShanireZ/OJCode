#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], ls[100005], read();
int main()
{
    int T = read();
    while (T--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
        {
            ls[i] = a[i] = read();
        }
        sort(ls + 1, ls + 1 + n);
        int m = unique(ls + 1, ls + 1 + n) - (ls + 1);
        for (int i = 1; i <= n; i++)
        {
            cout << lower_bound(ls + 1, ls + 1 + m, a[i]) - ls << " ";
        }
        cout << "\n";
    }
    return 0;
}
int read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}