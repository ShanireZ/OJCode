#include <iostream>
#include <algorithm>
using namespace std;
int ns[5000005];
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> ns[i];
    }
    nth_element(ns, ns + k, ns + n);
    cout << ns[k];
    return 0;
}