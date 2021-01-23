#include <iostream>
using namespace std;
int main()
{
    char output[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int pos[30] = {0};
    int x, m, i = 0;
    cin >> x >> m;
    while (x)
    {
        pos[i++] = x % m;
        x /= m;
    }
    for (i = i - 1; i >= 0; i--)
    {
        cout << output[pos[i]];
    }
    return 0;
}