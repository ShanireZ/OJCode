#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int p1 = a - b, p2 = a + b;
    if (p1 < 0 && p2 > n)
    {
        cout << "No solution" << endl;
    }
    if (p1 >= 0)
    {
        cout << p1 << " ";
    }
    if (p1 != p2 && p2 <= n)
    {
        cout << p2;
    }
    return 0;
}