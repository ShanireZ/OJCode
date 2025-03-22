#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main()
{
    int n, k, res = 0;
    cin >> n >> k;
    q.push(n);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (now - k <= 0 || (now - k) % 2 != 0)
        {
            res++;
        }
        else
        {
            q.push((now - k) / 2 + k);
            q.push((now - k) / 2);
        }
    }
    cout << res << endl;
    return 0;
}