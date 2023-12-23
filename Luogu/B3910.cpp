#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, pre, ans = 0;
    cin >> n >> pre;
    for (int i = 1; i <= n; i++)
    {
        int now;
        cin >> now;
        if ((now > 0 && pre < 0) || (now < 0 && pre > 0))
        {
            ans++;
        }
        pre = now;
    }
    cout << ans << endl;
    return 0;
}