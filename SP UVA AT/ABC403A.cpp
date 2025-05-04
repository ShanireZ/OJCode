#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (i % 2 == 1)
        {
            tot += a;
        }
    }
    cout << tot << endl;
    return 0;
}