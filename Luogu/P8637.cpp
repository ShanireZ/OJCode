#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, a[10005], p[10005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
        {
            continue;
        }
        ans++;
        int oth = a[i], poth = p[i];
        p[oth] = poth, a[poth] = oth;
    }
    cout << ans << endl;
    return 0;
}