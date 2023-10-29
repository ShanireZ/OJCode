#include <iostream>
using namespace std;
int main()
{
    int m, n, tot = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            tot += i;
        }
    }
    cout << tot << endl;
    return 0;
}