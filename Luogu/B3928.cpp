#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int n, ans, u[50005], v[50005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(u + 1, u + n + 1), sort(v + 1, v + n + 1);
    for (int i = 1, j = 1; i <= n; i++)
    {
        if (u[i] > v[j])
        {
            ans++, j++;
        }
    }
    cout << ans << endl;
    return 0;
}