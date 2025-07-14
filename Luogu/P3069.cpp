#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<int, int> ys;
int n, k, ans, c, cnt[100005], a[100005];
int main()
{
    cin >> n >> k;
    for (int i = 1, j = 1; i <= n; i++) // 双指针 合法取余内最多允许k+1种奶牛
    {
        cin >> a[i];
        if (ys[a[i]] == 0)
        {
            ys[a[i]] = i;
        }
        cnt[ys[a[i]]]++;
        c += (cnt[ys[a[i]]] == 1);
        while (c > k + 1)
        {
            cnt[ys[a[j]]]--;
            c -= (cnt[ys[a[j]]] == 0);
            j++;
        }
        ans = max(ans, cnt[ys[a[i]]]);
    }
    cout << ans << endl;
    return 0;
}