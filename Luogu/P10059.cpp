#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
struct Node
{
    int id, v;
};
deque<Node> q1, q2;
int a[100005], cnt[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ans = 0x7f7f7f7f, len = n - k + 1; // 区间越长极差越大,所以贪心取最长的区间
        q1.clear(), q2.clear();
        for (int r = 1; r <= n; r++)
        {
            int l = r - len + 1;
            while (q1.size() && q1.front().id < l)
            {
                q1.pop_front();
            }
            while (q1.size() && q1.back().v <= a[r])
            {
                q1.pop_back();
            }
            q1.push_back(Node{r, a[r]});
            while (q2.size() && q2.front().id < l)
            {
                q2.pop_front();
            }
            while (q2.size() && q2.back().v >= a[r])
            {
                q2.pop_back();
            }
            q2.push_back(Node{r, a[r]});
            if (r >= len)
            {
                ans = min(ans, q1.front().v - q2.front().v);
            }
        }
        cout << ans << " ";
        q1.clear(), q2.clear();
        memset(cnt, 0, sizeof(cnt));
        for (int l = 1, r = 0; l <= n; l++) // 枚举左端点
        {
            while (q1.size() && q1.front().id < l)
            {
                q1.pop_front();
            }
            while (q2.size() && q2.front().id < l)
            {
                q2.pop_front();
            }
            while ((q1.size() == 0 || q2.size() == 0 || q1.front().v - q2.front().v < ans) && r < n)
            {
                r++;
                while (q1.size() && q1.back().v <= a[r])
                {
                    q1.pop_back();
                }
                q1.push_back(Node{r, a[r]});
                while (q2.size() && q2.back().v >= a[r])
                {
                    q2.pop_back();
                }
                q2.push_back(Node{r, a[r]});
            }
            if (q1.front().v - q2.front().v >= ans) // 以l为左端点 以r~n为右端点的区间都满足条件
            {
                cnt[r - l + 1]++, cnt[n - l + 2]--;
            }
        }
        for (int i = 1; i <= len; i++)
        {
            cnt[i] = cnt[i - 1] + cnt[i];
            if (cnt[i] >= k)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}