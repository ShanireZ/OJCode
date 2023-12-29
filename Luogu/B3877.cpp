#include <algorithm>
#include <iostream>
using namespace std;
long long s[1000005];
int main()
{
    long long n, w, cnt = 1, pre = 0, ans = 0;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cnt = (w == pre ? min(3ll, cnt + 1) : 1);
        s[w] += cnt, ans = max(ans, s[w]);
        pre = w, w = (w * 3703 + 1047) % n + 1;
    }
    cout << ans << endl;
    return 0;
}
// TAG: 模拟