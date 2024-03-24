#include <algorithm>
#include <iostream>
using namespace std;
int f(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return f(x - 1) + x;
}
int main()
{
    int n;
    cin >> n;
    int tot = f(n);
    cout << tot << endl;
    return 0;
}