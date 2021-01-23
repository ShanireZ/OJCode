#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        x = (x + 1) * 2;
    }
    cout << x;
    return 0;
}