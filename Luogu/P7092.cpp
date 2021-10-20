#include <iostream>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    if(n / 2 * 2 + (n + 1) / 2 <= d)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " " << i << " ";
    }
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }
    return 0;
}