#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tLocal = 5 * n;
    int tLuogu = 3 * n + 11;
    if(tLocal < tLuogu)
    {
        cout << "Local";
    }
    else
    {
        cout << "Luogu";
    }
    return 0;
}