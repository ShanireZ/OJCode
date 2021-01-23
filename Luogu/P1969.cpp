#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int last = 0;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;
        total += max(height - last, 0);
        last = height;
    }
    cout << total;
    return 0;
}