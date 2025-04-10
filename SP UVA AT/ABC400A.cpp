#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (400 % n == 0)
    {
        cout << 400 / n << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}