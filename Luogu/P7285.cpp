#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            cnt += x;
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}