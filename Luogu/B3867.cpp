#include <algorithm>
#include <iostream>
using namespace std;
int ns[1005];
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= d; i++)
    {
        int a;
        cin >> a;
        ns[a] += i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ns[i] << " ";
    }
    return 0;
}