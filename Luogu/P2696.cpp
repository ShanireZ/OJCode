#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> v;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (true)
    {
        int cnt = 0;
        while (q.size() > 1)
        {
            int x = q.front();
            q.pop();
            if (cnt == 1)
            {
                v.push_back(x);
            }
            else
            {
                q.push(x);
            }
            cnt = (cnt + 1) % 2;
        }
        int now = q.front();
        q.pop();
        sort(v.begin(), v.end());
        for (int x : v)
        {
            if (x <= now)
            {
                q.push(x);
            }
            else
            {
                ans++;
            }
        }
        q.push(now), v.clear();
        if ((int)q.size() == n)
        {
            ans += q.size() * 2;
            break;
        }
        n = q.size();
    }
    cout << ans << endl;
    return 0;
}