#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q[1005], od;
int tid[1000005], t, tpos;
int main()
{
    cin >> t;
    while (t)
    {
        cout << "Scenario #" << ++tpos << endl;
        while (od.size())
        {
            od.pop();
        }
        for (int i = 1; i <= t; i++)
        {
            while (q[i].size())
            {
                q[i].pop();
            }
            int n, x;
            cin >> n;
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                tid[x] = i;
            }
        }
        string str;
        cin >> str;
        while (str != "STOP")
        {
            if (str == "ENQUEUE")
            {
                int x;
                cin >> x;
                q[tid[x]].emplace(x);
                if (q[tid[x]].size() == 1)
                {
                    od.emplace(tid[x]);
                }
            }
            else
            {
                cout << q[od.front()].front() << endl;
                q[od.front()].pop();
                if (q[od.front()].empty())
                {
                    od.pop();
                }
            }
            cin >> str;
        }
        cout << endl;
        cin >> t;
    }
    return 0;
}