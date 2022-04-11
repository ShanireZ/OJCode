#include <iostream>
using namespace std;
long long rd[100005];
long long action(int len, long long mid)
{
    long long cnt = 0, now = 0;
    for (int i = 1; i <= len; i++)
    {
        now = max(0ll, now + rd[i]);
        if (now >= mid)
        {
            now = 0;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int len, k;
    cin >> len >> k;
    for (int i = 1; i <= len; i++)
    {
        cin >> rd[i];
    }
    long long l = 1, r = 1e15, ans1 = 0, ans2 = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long cnt = action(len, mid);
        cnt > k ? l = mid + 1 : r = mid - 1;
        if (cnt == k)
        {
            ans1 = mid;
        }
    }
    l = 1, r = 1e15;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long cnt = action(len, mid);
        cnt >= k ? l = mid + 1 : r = mid - 1;
        if (cnt == k)
        {
            ans2 = mid;
        }
    }
    if (ans1 == 0 || ans2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}