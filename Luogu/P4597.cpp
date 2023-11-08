#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long> q;
int main()
{
    long long n, x, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        q.push(x);
        if (x < q.top())
        {
            ans += abs(x - q.top());
            q.pop();
            q.push(x);
        }
    }
    cout << ans << endl;
    return 0;
}