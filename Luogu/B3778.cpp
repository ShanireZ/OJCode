#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n <= 3 && a < b && a < c)
    {
        cout << "library";
    }
    else if (n <= 5 && b < c)
    {
        cout << "comprehensive";
    }
    else
    {
        cout << "art";
    }
    return 0;
}