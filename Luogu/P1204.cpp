#include <iostream>
#include <algorithm>
using namespace std;
struct Work
{
    int start, end, last;
};
bool cmp_start(Work a, Work b)
{
    return a.start < b.start;
}
bool cmp_final(Work a, Work b)
{
    if (a.start == b.start)
    {
        return a.last < b.last;
    }
    return a.start < b.start;
}
Work works[5001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> works[i].start >> works[i].end;
    }
    sort(works, works + n, cmp_start);
    for (int i = 1; i < n; i++)
    {
        if (works[i].start <= works[i - 1].end)
        {
            works[i].start = works[i - 1].start;
            works[i].end = max(works[i].end, works[i - 1].end);
            works[i - 1].start = 0;
            works[i - 1].end = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        works[i].last = works[i].end - works[i].start;
        if (works[i].last != 0)
        {
            sum++;
        }
    }
    sort(works, works + n, cmp_final);
    int workTime = works[n - sum].last, restTime = 0;
    for (int i = n - sum + 1; i < n; i++)
    {
        workTime = max(workTime, works[i].last);
        restTime = max(restTime, works[i].start - works[i - 1].end);
    }
    cout << workTime << " " << restTime;
    return 0;
}