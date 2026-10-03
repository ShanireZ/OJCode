#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int T, k;
priority_queue<int> q;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> k;
        int tot = 0;
        for (int i = 1; i <= k; i++)
        {
            char ch;
            cin >> ch;
            q.push(ch - '0');
            if ((int)q.size() > i / 2)
            {
                q.pop();
            }
            tot += (ch - '0');
        }
        int g = 0;
        while (q.size())
        {
            g += q.top();
            q.pop();
        }
        cout << (tot - g) * 10 + g << endl;
    }
    return 0;
}