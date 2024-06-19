#include <algorithm>
#include <iostream>
using namespace std;
long long all[100005], x;
int main()
{
    cin >> x;
    for (long long i = 1; i <= 100000; i++)
    {
        all[i] = i * i * i;
    }
    int p = upper_bound(all + 1, all + 1 + 100000, x) - all - 1;
    cout << p << endl;
    return 0;
}