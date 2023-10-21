#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > n / 2)
        {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
        for (int i = k * 2 + 1; i <= n; i++)
        {
            cout << i << " ";
        }
        for (int i = 1; i <= k * 2; i += 2)
        {
            int now = i;
            while (now <= k * 2)
            {
                cout << now << " ";
                now += now;
            }
        }
        cout << endl;
    }
    return 0;
}