#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<int> mn;
multiset<int, greater<int>> mx;
int a[3000005], read();
int main()
{
    int k = read(), n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int l = 1, r = 0, ans = 1;
    while (r < n)
    {
        r++;
        mx.insert(a[r]), mn.insert(a[r]);
        while (*mx.begin() - *mn.begin() > k)
        {
            ans = max(ans, r - l);
            mx.erase(mx.lower_bound(a[l]));
            mn.erase(mn.lower_bound(a[l]));
            l++;
        }
    }
    printf("%d\n", max(ans, r - l + 1));
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