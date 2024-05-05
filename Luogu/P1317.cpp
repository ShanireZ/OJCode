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
        if (now > pre && ok) // 之前下降过,现在开始上升了,形成了沟壑
        {
            ans++, ok = 0;
        }
        if (now < pre) // 开始下降
        {
            ok = 1;
        }
        pre = now;
    }
    cout << ans << endl;
    return 0;
}