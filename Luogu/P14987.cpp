#include <algorithm>
#include <iostream>
using namespace std;
int t, a[5];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        sort(a + 1, a + 5);
        cout << (a[1] == a[2] && a[3] == a[4] ? "Yes" : "No") << endl;
    }
    return 0;
}