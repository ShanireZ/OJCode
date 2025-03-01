#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> q;
vector<int> bt[505];
int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        q.emplace(a);
    }
    while (q.size())
    {
        for (int i = 1; q.size() && i <= p; i++)
        {
            bt[i].emplace_back(q.top());
            q.pop();
        }
        for (int i = p; q.size() && i >= 1; i--)
        {
            bt[i].emplace_back(q.top());
            q.pop();
        }
    }
    for (int i = 1; i <= p; i++)
    {
        for (int x : bt[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}