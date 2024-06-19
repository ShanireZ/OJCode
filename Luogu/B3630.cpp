#include <algorithm>
#include <iostream>
using namespace std;
int nxt[1000005], now, n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        nxt[i] = now;
    }
    cin >> now;
    while (now)
    {
        cout << now << " ";
        now = nxt[now];
    }
    return 0;
}