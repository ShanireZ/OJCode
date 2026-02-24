#include <algorithm>
#include <iostream>
using namespace std;
int n, p1, pn;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            p1 = i;
        }
        else if(x == n)
        {
            pn = i;
        }
    }
    cout << (p1 - 1) + (n - pn) - (pn < p1) << endl;
    return 0;
}