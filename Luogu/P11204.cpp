#include <iostream>
using namespace std;
int main()
{
    int T, n, m;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        int mn = m / n;
        int mx = mn + (m % n != 0);
        if (mn == 1 && mx == 2)
        {
            cout << (m % n < n - 1 ? "No" : "Yes") << endl;
            continue;
        }
        cout << (mn + mn > mx && mn > 0 ? "Yes" : "No") << endl;
    }
    return 0;
}