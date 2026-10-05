#include <algorithm>
#include <iostream>
using namespace std;
long long n, a[500005], sum[500005];
bool dfs(int l, int r)
{
    if (l == r)
    {
        return 1;
    }
    for (int i = l; i < r; i++)
    {
        long long d = (sum[i] - sum[l - 1]) - (sum[r] - sum[i]);
        if (d == 0 || d == 1)
        {
            return dfs(l, i) && dfs(i + 1, r);
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cout << (dfs(1, n) ? "Yes" : "No") << endl;
    return 0;
}