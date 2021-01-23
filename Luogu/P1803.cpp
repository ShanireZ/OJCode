#include <iostream>
#include <algorithm>
using namespace std;
struct Match
{
    int start, end;
};
Match matches[1000005];
bool cmp(Match a, Match b)
{
    return a.end < b.end;
}

int main()
{
    int n, total = 0, pos = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> matches[i].start >> matches[i].end;
    }
    sort(matches, matches + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (matches[i].start < pos)
        {
            continue;
        }
        total++;
        pos = matches[i].end;
    }
    cout << total;
    return 0;
}