#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int n, p;
        cin >> n >> p;
        if (p * 2 + 1 > n)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= (n - p * 2 - 1); i++)
        {
            cout << 0;
        }
        for (int i = 1; i <= p; i++)
        {
            cout << 10;
        }
        cout << 1 << endl;
    }
    return 0;
}