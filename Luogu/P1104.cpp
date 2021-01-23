#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Stu
{
    string name;
    int y, m, d, id;
};
bool cmp(Stu a, Stu b)
{
    if (a.y == b.y)
    {
        if (a.m == b.m)
        {
            if (a.d == b.d)
            {
                return a.id > b.id;
            }
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    return a.y < b.y;
}
Stu stu[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;
        stu[i].id = i;
    }
    sort(stu + 1, stu + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << stu[i].name << endl;
    }
    return 0;
}