#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h, m, s, ans = 0;
    char sx;
    cin >> h >> m >> s >> sx;
    if (sx == 'P')
    {
        ans += 12 * 3600;
    }
    ans += h * 3600 + m * 60 + s;
    cout << ans << endl;
    return 0;
}
// TAG: 分支 模拟