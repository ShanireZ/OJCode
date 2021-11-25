#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int a[25], b[25];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    long long now = 1, ans = 1;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] <= b[now])
        {
            now++;
        }
        ans *= now - i;
    }
    cout << ans << endl;
    return 0;
}