#include <iostream>
#include <set>
using namespace std;
set<int> day[1005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) //学生编号
    {
        for (int j = 1; j <= m; j++)
        {
            int d; //天数
            cin >> d;
            day[d].insert(j);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << day[i].size() << " ";
    }
    return 0;
}