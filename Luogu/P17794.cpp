#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, lst = 0, now = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        now = now * 2 + 1 + (lst == x) * 2;
        lst = x;
    }
    cout << now << endl;
    return 0;
}