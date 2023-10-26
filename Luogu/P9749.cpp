#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v[100005];
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    long long n, d, ans = 0, ex = 0;
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
        long long x = ceil(1.0 * (v[i] - ex) / d);
        ans += x * q.top(), ex += x * d - v[i];
    }
    cout << ans << endl;
    return 0;
}
// TAG: 贪心 优先队列 集合