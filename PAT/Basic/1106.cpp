#include <iostream>
using namespace std;
int n[10005] = {0, 2, 0, 1, 9};
int main()
{
    int x;
    cin >> x;
    for (int i = 5; i <= x; i++)
    {
        n[i] = (n[i - 1] + n[i - 2] + n[i - 3] + n[i - 4]) % 10;
    }
    for (int i = 1; i <= x; i++)
    {
        cout << n[i];
    }
    return 0;
}