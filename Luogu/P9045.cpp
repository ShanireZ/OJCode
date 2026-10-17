#include <algorithm>
#include <iostream>
using namespace std;
int vis[500005], n, k, x;
int main()
{
    cin >> n >> k;
    long long ans = -(long long)k * (k + 1) / 2; // 前k種飲料最終位置
    for (int i = 1; i <= n; i++)                 // 前k種飲料初始位置
    {
        cin >> x;
        if (vis[x] == 0 && k)
        {
            vis[x] = 1, ans += i, k--;
        }
    }
    cout << (k != 0 ? -1 : ans) << endl; // 最終-初始=需要移動的次數
    return 0;
}