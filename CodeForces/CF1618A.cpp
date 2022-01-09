#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[10] = {0};
        for (int i = 1; i <= 7; i++)
        {
            cin >> a[i];
        }
        cout << a[1] << " " << a[2] << " " << a[7] - a[1] - a[2] << endl;
    }
    return 0;
}