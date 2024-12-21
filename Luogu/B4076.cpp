#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = max(a, b); i <= 6; i++)
    {
        cout << i << " ";
    }
    return 0;
}