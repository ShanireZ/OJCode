#include <algorithm>
#include <iostream>
using namespace std;
int vis[1000005], a[1005], n, cnt;
int main()
{
    for (int i = 0; i <= 1000; i++)
    {
        vis[i * i] = 1;
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j++)
        {
            if (vis[a[i] + a[j]] == 1)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}