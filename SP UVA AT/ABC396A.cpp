#include <iostream>
using namespace std;
int a[105];
int main()
{
    int n;
    cin >> n >> a[1] >> a[2];
    for (int i = 3; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1] && a[i] == a[i - 2])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}