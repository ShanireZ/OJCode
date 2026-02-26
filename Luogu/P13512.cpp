#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int n, p, a, cnt, tot;
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        while (q.size() && tot - q.top() + a >= p && q.top() < a)
        {
            tot -= q.top(), cnt--;
            q.pop();
        }
        if (tot < p)
        {
            tot += a, cnt++, q.push(a);
        }
        cout << (tot >= p ? cnt : -1) << " ";
    }
    return 0;
}