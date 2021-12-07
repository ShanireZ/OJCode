#include <iostream>
#include <set>
#include <queue>
using namespace std;
set<int> s;
priority_queue<int> q;
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) //统计每一个亲戚所在的位置
    {
        int x;
        cin >> x;
        x = x / 12 + 1;
        ans = max(ans, x); //首先传送回最早的亲戚那里
        s.insert(x);
    }
    int pre = 0;
    for (auto it = s.begin(); it != s.end(); it++) //统计所有可以用时光机的间隔
    {
        int x = *it - pre - 1;
        if (x != 0)
        {
            q.push(x);
        }
        pre = *it;
    }
    for (int i = 1; i <= k - 1; i++) //选择最大的k-1个间隔使用时光机
    {
        ans -= q.top();
        q.pop();
    }
    cout << ans * 12 << endl;
    return 0;
}