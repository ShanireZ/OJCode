#include <iostream>
#include <queue>
using namespace std;
deque<int> q;
int v[1000005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        while (q.size() && v[q.back()] >= v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        while (q.size() && q.front() < i - k + 1)
        {
            q.pop_front();
        }
        if (i < k)
        {
            continue;
        }
        cout << v[q.front()] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && v[q.back()] <= v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        while (q.size() && q.front() < i - k + 1)
        {
            q.pop_front();
        }
        if (i < k)
        {
            continue;
        }
        cout << v[q.front()] << " ";
    }
    return 0;
}