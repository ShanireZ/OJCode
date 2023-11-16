#include <algorithm>
#include <iostream>
using namespace std;
long long bt[300005], n, ans;
int lb(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        bt[x]++;
        x += lb(x);
    }
}
long long query(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += bt[x];
        x -= lb(x);
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x++;
        ans += query(x);
        edit(x);
    }
    cout << ans << endl;
    return 0;
}