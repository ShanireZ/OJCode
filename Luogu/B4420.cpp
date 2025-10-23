#include <algorithm>
#include <iostream>
using namespace std;
int a[105], n, k, x;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> k >> x;
    for (int i = 1, cnt = 0; i <= n; i++)
    {
        cnt += (a[i] == x);
        if (cnt == k)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "Error" << endl;
    return 0;
}