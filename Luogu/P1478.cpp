#include <algorithm>
#include <iostream>
using namespace std;
int apples[5005];
int main()
{
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > a + b)
        {
            continue;
        }
        cnt++;
        apples[cnt] = y;
    }
    sort(apples + 1, apples + 1 + cnt);
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (apples[i] > s)
        {
            break;
        }
        else
        {
            ans++;
            s -= apples[i];
        }
    }
    cout << ans << endl;
    return 0;
}