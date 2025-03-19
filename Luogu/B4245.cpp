#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cin >> n >> a;
    cout << a;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        cout << ',' << a;
    }
    return 0;
}