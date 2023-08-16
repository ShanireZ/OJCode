#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tot += 21 - x * 2 - (x % 2 == 1 ? 1 : -1) + (i == n) * x;
    }
    cout << tot << endl;
    return 0;
}