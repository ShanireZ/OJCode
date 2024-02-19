#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    int tot = a + b;
    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b, b = c, tot += c;
        if (c >= m)
        {
            break;
        }
    }
    cout << tot << endl;
    return 0;
}