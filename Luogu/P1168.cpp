#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> qx;
priority_queue<int, vector<int>, less<int>> qd;
int main()
{
    int n, x;
    cin >> n;
    for (int i = 1, sz = 1; i <= n; i++)
    {
        cin >> x;
        qd.push(x);
        if (qd.size() > sz)
        {
            qx.push(qd.top()), qd.pop();
        }
        if (i % 2 == 1)
        {
            cout << qd.top() << endl;
            sz++;
            if (qx.size())
            {
                qd.push(qx.top()), qx.pop();
            }
        }
    }
    return 0;
}