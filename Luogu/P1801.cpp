#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> qx;
priority_queue<int, vector<int>, less<int>> qd;
int a[200005], n, m, now = 1;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1, p = 1; i <= m; i++)
    {
        int last;
        cin >> last;
        while (now <= last)
        {
            qd.push(a[now]);
            now++;
        }
        while ((int)qd.size() >= p)
        {
            qx.push(qd.top()), qd.pop();
        }
        cout << qx.top() << endl;
        p++, qd.push(qx.top()), qx.pop();
    }
    return 0;
}