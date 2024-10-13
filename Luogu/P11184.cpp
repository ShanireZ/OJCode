#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        if (k == 0)
        {
            cout << 1 << endl;
            continue;
        }
        long long r = n / k, l = n / (k + 1);
        cout << r - l << endl;
    }
    return 0;
}