#include <functional>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> up;
priority_queue<int, vector<int>, less<int>> down;
int main()
{
    int n;
    cin >> n;
    int sz = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        down.push(x);
        if (int(down.size()) > sz)
        {
            up.push(down.top());
            down.pop();
        }
        if (i % 2 == 1)
        {
            cout << up.top() << endl;
            down.push(up.top());
            up.pop();
        }
    }
    return 0;
}