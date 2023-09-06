#include <algorithm>
#include <iostream>
using namespace std;
int p[105];
int main()
{
    int n, cnt = 0, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cin >> tot;
    for (int i = 1; i <= n; i++)
    {
        if (tot >= p[i])
        {
            cnt++, tot -= p[i];
        }
    }
    cout << cnt << endl;
    return 0;
}
// TAG: 模拟 枚举