#include <iostream>
using namespace std;
int ans[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            ans[j] += x;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = (ans[i] > m / 2) ? 1 : 0;
        int x;
        cin >> x;
        if (ans[i] == x)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}