#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        res += (i % 10 == 3);
    }
    cout << res << endl;
    return 0;
}