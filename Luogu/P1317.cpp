#include <algorithm>
#include <iostream>
using namespace std;
int n, now, pre, ok, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        if (now > pre && ok) // 之前下降過,現在開始上升了,形成了溝壑
        {
            ans++, ok = 0;
        }
        if (now < pre) // 開始下降
        {
            ok = 1;
        }
        pre = now;
    }
    cout << ans << endl;
    return 0;
}