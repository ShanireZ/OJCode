#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, total = 0;
    cin >> n;
    int fru[n];
    memset(fru, 0, sizeof(fru));
    for (int i = 0; i < n; i++)
    {
        cin >> fru[i];
    }
    make_heap(fru, fru + n, cmp);
    for (int i = 0; i < n - 1; i++)
    {
        pop_heap(fru, fru + n - i, cmp);
        pop_heap(fru, fru + n - i - 1, cmp);
        fru[n - 2 - i] = fru[n - 1 - i] + fru[n - 2 - i];
        total += fru[n - 2 - i];
        push_heap(fru, fru + n - i - 1, cmp);
    }
    cout << total;
    return 0;
}