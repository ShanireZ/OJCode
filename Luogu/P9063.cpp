#include <iostream>
using namespace std;
int main()
{
    long long t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (n % 2 == 0 ? "No" : "Yes") << "\n";
    }
    return 0;
}