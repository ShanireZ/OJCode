#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    if (x % 2 == l % 2)
    {
        cout << "L" << endl;
    }
    else
    {
        cout << "R" << endl;
    }
    return 0;
}