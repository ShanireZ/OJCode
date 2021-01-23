#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Runner
{
    int time;
    string name;
};

bool cmp(Runner a, Runner b)
{
    return a.time < b.time;
}

int main()
{
    int n, k;
    cin >> n >> k;
    Runner runners[n];
    for (int i = 0; i < n; i++)
    {
        cin >> runners[i].name >> runners[i].time;
    }
    sort(runners, runners + n, cmp);
    cout << runners[k - 1].name;
    return 0;
}