#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x >= 90 && x <= 140 && y >= 60 && y <= 90)
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}