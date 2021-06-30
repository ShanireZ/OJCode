#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long n, k, s;
        cin >> n >> k >> s;
        long long mins = (1 + k) * k / 2;
        long long maxs = ((n - k + 1) + n) * k / 2;
        if (s >= mins && s <= maxs)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}