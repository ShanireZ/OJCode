#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> qx;
priority_queue<int, vector<int>, less<int>> qd;
int main()
{
    int n;
    cin >> n;
    for (int i = 1, p = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        qd.push(x);
        while ((int)qd.size() == p)
        {
            qx.push(qd.top()), qd.pop();
        }
        if (i % 2 == 1)
        {
            cout << qx.top() << endl;
            p++, qd.push(qx.top()), qx.pop();
        }
    }
    return 0;
}