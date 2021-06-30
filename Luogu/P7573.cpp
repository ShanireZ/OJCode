#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << (n + 1) / 2 << endl;
        }
    }
    return 0;
}