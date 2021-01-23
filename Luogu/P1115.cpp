#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tmp;
    cin >> tmp;
    int total = tmp, max_total = tmp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        if (total < 0)
        {
            total = tmp;
        }
        else
        {
            total += tmp;
        }
        max_total = max(max_total, total);
    }
    cout << max_total;
    return 0;
}