#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, sum = 0, now = 1;
    cin >> n;
    while (sum < n)
    {
        if (sum + now * 7 < n)
        {
            sum += now++ * 7;
        }
        else
        {
            cout << (now - 1) * 7 + (n - sum + now - 1) / now << endl;
            break;
        }
    }
    return 0;
}