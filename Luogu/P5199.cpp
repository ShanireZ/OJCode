#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Mountain
{
    int x, y, left, right;
    void count_frontier()
    {
        left = x - y;
        right = x + y;
    }
};

bool cmp(Mountain a, Mountain b)
{
    if (a.left == b.left)
    {
        return a.right > b.right;
    }
    return a.left < b.left;
}

Mountain mts[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mts[i].x >> mts[i].y;
        mts[i].count_frontier();
    }
    sort(mts, mts + n, cmp);

    int total = 1;
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (mts[i].left >= mts[pos].left && mts[i].right <= mts[pos].right)
        {
            continue;
        }
        pos = i;
        total++;
    }
    cout << total;
    return 0;
}