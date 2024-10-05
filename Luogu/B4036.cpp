#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, tot = 0;
        cin >> x;
        while (x)
        {
            tot += x % 10;
            x /= 10;
        }
        cout << (tot % 7 == 0 ? "Yes" : "No") << endl;
    }
    return 0;
}