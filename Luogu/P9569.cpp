#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, T, id = 1, ans = 0;
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
    {
        long long v, t;
        cin >> v >> t;
        long long h = (T - t) * v;
        if (h > ans)
        {
            ans = h, id = i;
        }
    }
    cout << id << endl;
    return 0;
}
// TAG: 枚举 模拟 最值