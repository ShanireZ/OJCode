#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> q1, q2;
int m, n1, n2, v, pos[10005];
int main()
{
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v;
        if (pos[v] == 0)
        {
            q2.insert(q2.begin(), v), pos[v] = 2;
            if (q2.size() > n2)
            {
                v = q2.back();
                q2.pop_back(), pos[v] = 0;
            }
            continue;
        }
        if (pos[v] == 1)
        {
            auto it = find(q1.begin(), q1.end(), v);
            q1.erase(it);
        }
        else
        {
            auto it = find(q2.begin(), q2.end(), v);
            q2.erase(it);
        }
        q1.insert(q1.begin(), v), pos[v] = 1;
        if (q1.size() > n1)
        {
            v = q1.back();
            q1.pop_back(), pos[v] = 0;
            if (q2.size() != n2)
            {
                q2.insert(q2.begin(), v), pos[v] = 2;
            }
        }
    }
    for (int x : q1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x : q2)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}