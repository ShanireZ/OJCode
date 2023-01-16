#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long t, n;
    cin >> t;
    while (t--)
    {
        long long m;
        cin >> n >> m;
        if (n > __lg(m) + 1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            long long now = 1;
            for (int i = 1; i <= n; i++)
            {
                cout << now << " ";
                now *= 2;
            }
            cout << "\n";
        }
    }
    return 0;
}