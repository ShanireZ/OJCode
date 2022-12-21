#include <iostream>
#include <queue>
using namespace std;
int times[100005], ans = 0;
queue<pair<int, int>> q;
int main()
{
    int n, k;
    cin >> n >> k;
    q.push(make_pair(0, 1)), times[0] = 1;
    while (q.size())
    {
        int now = q.front().first, step = q.front().second;
        q.pop();
        ans = max(ans, step);
        if (times[(now + 1) % n] == 0)
        {
            times[(now + 1) % n] = step + 1;
            q.push(make_pair((now + 1) % n, step + 1));
        }
        if (times[(now + k) % n] == 0)
        {
            times[(now + k) % n] = step + 1;
            q.push(make_pair((now + k) % n, step + 1));
        }
    }
    cout << ans - 1 << "\n"; // 初始状态为了区分是否到达设置为1多了一步,实际为0
    return 0;
}