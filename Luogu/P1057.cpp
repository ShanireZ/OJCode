#include <iostream>
#include <cstring>
using namespace std;
int projects[31][31];
int n, m;
int make_project(int a, int b) //计算方案数
{
    if (projects[a][b] == -1)
    {
        int left = a - 1, right = a + 1;
        if (a - 1 < 1)
        {
            left += n;
        }
        if (a + 1 > n)
        {
            right -= n;
        }
        projects[a][b] = make_project(left, b - 1) + make_project(right, b - 1); //球只能从左右传过来
    }
    return projects[a][b];
}
int main()
{
    cin >> n >> m;
    memset(projects, -1, sizeof(projects));
    projects[1][0] = 1;          //小蛮初始状态
    for (int i = 2; i <= n; i++) //其他人初始拿不到球
    {
        projects[i][0] = 0;
    }
    cout << make_project(1, m);
    return 0;
}