#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n >= 200)
    {
        n -= 50;
    }
    if (n >= 100)
    {
        n -= 20;
    }
    cout << n << endl;
    return 0;
}