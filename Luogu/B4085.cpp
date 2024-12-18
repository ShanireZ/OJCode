#include <algorithm>
#include <iostream>
using namespace std;
int cnt[105], lst[105], vis[105][105];
int main()
{
    int n, t, p, k;
    cin >> n >> t >> p >> k;
    int ans1 = -1, ans2 = -1, ans3 = -1, ans4 = -1;
    for (int i = 1; i <= n; i++)
    {
        int tid, pid, state;
        cin >> tid >> pid >> state;
        if (state == 1) // AC
        {
            ans1 = tid;
            if (vis[tid][pid] == 0) // 有效AC
            {
                ans2 = tid;
                cnt[tid]++, vis[tid][pid] = 1, lst[tid] = i;
                if (cnt[tid] == 1)
                {
                    ans4 = tid;
                }
            }
        }
    }
    for (int i = 1; i <= t; i++)
    {
        if (cnt[i] > 0 && cnt[i] < k && (ans3 == -1 || lst[i] > lst[ans3]))
        {
            ans3 = i;
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
    return 0;
}