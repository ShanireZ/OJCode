#include <algorithm>
#include <iostream>
using namespace std;
int s[100005];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int w;
        cin >> w;
        if (w <= n && s[w] < 200)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}