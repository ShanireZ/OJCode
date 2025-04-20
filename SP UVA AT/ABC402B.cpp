#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int opt, x;
        cin >> opt;
        if (opt == 1)
        {
            cin >> x;
            q.emplace(x);
        }
        else
        {
            cout << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}