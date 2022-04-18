#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        long long n;
        cin >> k >> n;
        long long x = 0;
        for (int i = 1; i <= k; i++)
        {
            x = x * 10 + 9;
        }
        if (n % x == 0)
        {
            cout << "aya" << endl;
        }
        else
        {
            cout << "baka" << endl;
        }
    }
    return 0;
}