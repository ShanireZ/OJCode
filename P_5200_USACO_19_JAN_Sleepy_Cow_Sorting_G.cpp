#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    //freopen("sleepy.in", "r", stdin);
    //freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;
    int rank[n];
    memset(rank, 0, sizeof(rank));
    for (int i = 0; i < n; i++)
    {
        cin >> rank[i];
    }
    int step = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (rank[i] > rank[i + 1])
        {
            step = i + 1;
            break;
        }
    }
    cout << step;
    return 0;
}