/*
    把没有规律的提前进行初始化
    只能走1~2步，所以第三层是前两层的情况和
    记忆化搜索加快运算效率，避免重复运算
*/

#include <iostream>
using namespace std;
int ladders_project[31];

int ladders(int n)
{
    if (ladders_project[n] == 0)
    {
        ladders_project[n] = ladders(n - 1) + ladders(n - 2);
    }
    return ladders_project[n];
}

int main()
{
    ladders_project[1] = 1, ladders_project[2] = 2;
    int n;
    while (cin >> n)
    {
        cout << ladders(n) << endl;
    }
    return 0;
}