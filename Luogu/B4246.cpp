#include <algorithm>
#include <iostream>
using namespace std;
int a[5005], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int now = 1;
    while (m--)
    {
        int step = a[now] % n;
        now = (now - step + n) % n;
        if (now == 0)
        {
            now = n;
        }
    }
    cout << now << endl;
    return 0;
}