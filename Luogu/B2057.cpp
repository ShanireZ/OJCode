#include <iostream>
using namespace std;
int main()
{
    int n, zg = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cj;    //! 1.建立变量存储当前人的成绩
        cin >> cj; //! 2.输出当前人的成绩进变量里
        if (cj > zg) //! 3.判断新分数是否比之前的最高分还要高--->更新/不更新
        {
            zg = cj;
        }
    }
    cout << zg << endl;
    return 0;
}